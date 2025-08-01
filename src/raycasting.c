/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** wolf3d
*/

#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/struct_fb.h"

int is_wall(char cell)
{
    return (cell >= '1' && cell <= '9');
}

static int is_out_map(ray_t *ray, game_t *game)
{
    char cell;

    if (ray->map_y < 0 || ray->map_y >= game->mapping->height ||
        ray->map_x < 0 || ray->map_x >= game->mapping->width) {
        ray->hit = -1;
        return -1;
    }
    cell = game->mapping->map[ray->map_y][ray->map_x];
    if (is_wall(cell)) {
        ray->hit = 1;
    }
    return 0;
}

static void perform_dda(ray_t *ray, game_t *game)
{
    while (ray->hit == 0) {
        if (ray->side_dist_x < ray->side_dist_y) {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        } else {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (is_out_map(ray, game) == -1) {
            return;
        }
    }
}

void compute_projection(ray_t *ray, game_t *game)
{
    if (ray->side == 0)
    ray->perp_wall_dist = (ray->map_x - game->posX +
        (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
    else
    ray->perp_wall_dist = (ray->map_y - game->posY +
        (1 - ray->step_y) / 2.0) / ray->ray_dir_y;
    ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
    ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
    if (ray->draw_end >= SCREEN_HEIGHT)
        ray->draw_end = SCREEN_HEIGHT - 1;
}

void clear_framebuffer(sfUint8 *framebuffer)
{
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 4; i++) {
        framebuffer[i] = 0;
    }
}

void render_raycasting(game_t *game, ray_t *ray)
{
    clear_framebuffer(game->framebuffer);
    draw_ceiling(game);
    draw_floor(game);
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        init_raycasting_vars(ray, game, x);
        perform_dda(ray, game);
        if (ray->hit == 1) {
            compute_projection(ray, game);
            draw_textured_column(game, ray, x);
            game->zbuffer[x] = ray->perp_wall_dist;
        }
    }
    draw_entities(game);
    sfTexture_updateFromPixels(game->screen_texture, game->framebuffer,
        SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(game->window, game->screen_sprite, NULL);
}
 