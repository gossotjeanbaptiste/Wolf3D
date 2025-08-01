/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_game_graphics
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"
#include <math.h>
#include <stdbool.h>

static double dist_to_player(game_t *game, entity_t *ent)
{
    double dx = ent->x - game->posX;
    double dy = ent->y - game->posY;
    return dx*dx + dy*dy;
}

void sort_entities_by_distance(game_t *game)
{
    for (int i = 1; i < game->entity_count; i++) {
        entity_t *tmp = game->entities[i];
        double dist_tmp = dist_to_player(game, tmp);
        int j = i - 1;
        while (j >= 0 && dist_to_player(game, game->entities[j]) < dist_tmp) {
            game->entities[j + 1] = game->entities[j];
            j--;
        }
        game->entities[j + 1] = tmp;
    }
}

void draw_entities(game_t *game)
{
    sort_entities_by_distance(game);
    for (int i = 0; i < game->entity_count; i++) {
        entity_t *ent = game->entities[i];
        if (!ent || !ent->image) continue;

        float dx = ent->x - game->posX;
        float dy = ent->y - game->posY;

        float inv_det = 1.0f / (game->planeX * game->dirY - game->dirX * game->planeY);
        float transform_x = inv_det * (game->dirY * dx - game->dirX * dy);
        float transform_y = inv_det * (-game->planeY * dx + game->planeX * dy);

        if (transform_y <= 0) continue;

        int sprite_screen_x = (int)((SCREEN_WIDTH / 2) * (1 + transform_x / transform_y));
        int sprite_height = abs((int)(SCREEN_HEIGHT / transform_y));
        int sprite_width = sprite_height;

        int draw_start_y = -sprite_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_start_y < 0) draw_start_y = 0;
        int draw_end_y = sprite_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_end_y >= SCREEN_HEIGHT) draw_end_y = SCREEN_HEIGHT - 1;

        int draw_start_x = -sprite_width / 2 + sprite_screen_x;
        if (draw_start_x < 0) draw_start_x = 0;
        int draw_end_x = sprite_width / 2 + sprite_screen_x;
        if (draw_end_x >= SCREEN_WIDTH) draw_end_x = SCREEN_WIDTH - 1;

        if (ent->is_dead && ent->death_anim_frame < 4 && ent->death_clock) {
            sfTime time = sfClock_getElapsedTime(ent->death_clock);
            if (sfTime_asSeconds(time) > 0.12f) {
                ent->death_anim_frame++;
                sfClock_restart(ent->death_clock);
            }
        }

        int current_frame = ent->is_dead ? ent->death_anim_frame : 0;
        int frame_offset = current_frame * 64;

        sfVector2u size = sfImage_getSize(ent->image);

        for (int stripe = draw_start_x; stripe < draw_end_x; stripe++) {
            if (transform_y >= game->zbuffer[stripe]) continue;
            int tex_x = (stripe - (-sprite_width / 2 + sprite_screen_x)) * 64 / sprite_width;
            int px = tex_x + frame_offset;
            if (px < 0 || px >= (int)size.x) continue;

            for (int y = draw_start_y; y < draw_end_y; y++) {
                int d = y * 2 - SCREEN_HEIGHT + sprite_height;
                int tex_y = ((d * 64) / sprite_height) / 2;
                if (tex_y < 0 || tex_y >= (int)size.y) continue;

                sfColor color = sfImage_getPixel(ent->image, px, tex_y);
                if (color.a == 0) continue;

                put_pixel_with_flashlight(game, stripe, y, color);
            }
        }
    }
}

void check_monster_hit(game_t *game)
{
    int center_x = SCREEN_WIDTH / 2;
    float zbuffer = game->zbuffer[center_x];

    for (int i = 0; i < game->entity_count; i++) {
        entity_t *ent = game->entities[i];
        if (!ent || ent->is_dead) continue;

        float dx = ent->x - game->posX;
        float dy = ent->y - game->posY;

        float inv_det = 1.0 / (game->planeX * game->dirY - game->dirX * game->planeY);
        float transform_x = inv_det * (game->dirY * dx - game->dirX * dy);
        float transform_y = inv_det * (-game->planeY * dx + game->planeX * dy);

        if (transform_y <= 0) continue;

        int sprite_screen_x = (int)((SCREEN_WIDTH / 2) * (1 + transform_x / transform_y));
        int sprite_height = abs((int)(SCREEN_HEIGHT / transform_y));
        int sprite_width = sprite_height;

        int draw_start_x = sprite_screen_x - sprite_width / 2;
        int draw_end_x = sprite_screen_x + sprite_width / 2;

        if (center_x >= draw_start_x && center_x <= draw_end_x && transform_y < zbuffer) {
            ent->is_dead = 1;
            ent->death_anim_frame = 0;
            if (!ent->death_clock)
                ent->death_clock = sfClock_create();
            else
                sfClock_restart(ent->death_clock);
            break;
        }
    }
}

int init_entities_from_map(game_t *game)
{
    int count = 0;

    for (int y = 0; y < game->mapping->height; y++)
        for (int x = 0; x < game->mapping->width; x++)
            if (game->mapping->map[y][x] == 'M')
                count++;

    if (count == 0)
        return 0;

    game->entities = malloc(sizeof(entity_t *) * count);
    if (!game->entities)
        return 84;
    game->entity_count = count;

    int i = 0;
    for (int y = 0; y < game->mapping->height; y++) {
        for (int x = 0; x < game->mapping->width; x++) {
            if (game->mapping->map[y][x] != 'M') continue;

            entity_t *e = malloc(sizeof(entity_t));
            if (!e)
                return 84;

            e->x = x + 0.5;
            e->y = y + 0.5;
            e->is_dead = 0;
            e->death_anim_frame = 0;
            e->death_clock = sfClock_create();

            if (!e->death_clock) {
                free(e);
                return 84;
            }

            e->texture = sfTexture_createFromFile("assets/texture/monster.png", NULL);
            if (!e->texture) {
                fprintf(stderr, "Error 'monster.png' not found!\n");
                sfClock_destroy(e->death_clock);
                free(e);
                return 84;
            }

            e->image = sfTexture_copyToImage(e->texture);
            if (!e->image) {
                fprintf(stderr, "Error loading monster.png\n");
                sfTexture_destroy(e->texture);
                sfClock_destroy(e->death_clock);
                free(e);
                return 84;
            }
            game->entities[i++] = e;
        }
    }
    return 0;
}

void free_entities(game_t *game)
{
    if (!game || !game->entities)
        return;

    for (int i = 0; i < game->entity_count; i++) {
        entity_t *e = game->entities[i];
        if (!e)
            continue;

        if (e->texture)
            sfTexture_destroy(e->texture);
        if (e->image)
            sfImage_destroy(e->image);
        if (e->death_clock)
            sfClock_destroy(e->death_clock);

        free(e);
    }

    free(game->entities);
    game->entities = NULL;
    game->entity_count = 0;
}

static bool monster_can_see_player(game_t *game, entity_t *monster)
{
    double x0 = monster->x;
    double y0 = monster->y;
    double x1 = game->posX;
    double y1 = game->posY;

    double dx = x1 - x0;
    double dy = y1 - y0;
    double distance = sqrt(dx * dx + dy * dy);

    if (distance > 8.0)
        return false;

    int steps = (int)(distance * 20);
    for (int i = 1; i < steps; i++) {
        double t = (double)i / steps;
        double xi = x0 + dx * t;
        double yi = y0 + dy * t;
        int mx = (int)xi;
        int my = (int)yi;

        if (mx < 0 || my < 0 || mx >= game->mapping->width || my >= game->mapping->height)
            return false;

        char tile = game->mapping->map[my][mx];
        if (tile >= '1' && tile <= '9')
            return false;
    }
    return true;
}
static bool is_walkable(game_t *game, double x, double y)
{
    int mx = (int)x;
    int my = (int)y;

    if (mx < 0 || my < 0 || mx >= game->mapping->width || my >= game->mapping->height)
        return false;

    char tile = game->mapping->map[my][mx];

    if (tile >= '1' && tile <= '9')
        return false;

    return true;
}

static void move_monster(game_t *game, entity_t *m, float speed)
{
    if (m->is_dead)
        return;

    if (!monster_can_see_player(game, m))
        return;

    double dx = game->posX - m->x;
    double dy = game->posY - m->y;
    double dist = sqrt(dx * dx + dy * dy);

    if (dist < 0.4) {
        return;
    }

    dx /= dist;
    dy /= dist;

    double new_x = m->x + dx * speed;
    double new_y = m->y + dy * speed;

    if (is_walkable(game, new_x, m->y))
        m->x = new_x;
    if (is_walkable(game, m->x, new_y))
        m->y = new_y;
}

void update_monsters(game_t *game)
{
    float speed = 0.03f;

    for (int i = 0; i < game->entity_count; i++) {
        move_monster(game, game->entities[i], speed);
    }
}
