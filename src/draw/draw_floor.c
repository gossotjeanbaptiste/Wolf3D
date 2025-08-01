/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** draw_floor
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static void floor_init(ray_floor_t *rfloor, game_t *game, int y)
{
    rfloor->floor_texture = game->textures->walls[6];
    rfloor->ray_dix_x0 = game->dirX - game->planeX;
    rfloor->ray_dix_y0 = game->dirY - game->planeY;
    rfloor->ray_dix_x1 = game->dirX + game->planeX;
    rfloor->ray_dix_y1 = game->dirY + game->planeY;
    rfloor->vertical_pos = y - SCREEN_HEIGHT / 2;
    rfloor->pos_z = 0.5 * SCREEN_HEIGHT;
    rfloor->row_distance = rfloor->pos_z / rfloor->vertical_pos;
    rfloor->floor_step_x = rfloor->row_distance *
    (rfloor->ray_dix_x1 - rfloor->ray_dix_x0) / SCREEN_WIDTH;
    rfloor->floor_step_y = rfloor->row_distance *
    (rfloor->ray_dix_y1 - rfloor->ray_dix_y0) / SCREEN_WIDTH;
    rfloor->floor_x = game->posX + rfloor->row_distance * rfloor->ray_dix_x0;
    rfloor->floor_y = game->posY + rfloor->row_distance * rfloor->ray_dix_y0;
    rfloor->distance_factor = 1.0 - (rfloor->row_distance * 0.03);
    if (rfloor->distance_factor < 0.3f)
        rfloor->distance_factor = 0.3f;
}

static void draw_floor_pixel(game_t *game, ray_floor_t *rfloor, int x, int y)
{
    rfloor->tx = (int)(TEX_WIDTH * (rfloor->floor_x -
        floor(rfloor->floor_x))) % TEX_WIDTH;
    rfloor->ty = (int)(TEX_HEIGHT * (rfloor->floor_y -
        floor(rfloor->floor_y))) % TEX_HEIGHT;
    rfloor->color = sfImage_getPixel(rfloor->floor_texture,
        rfloor->tx, rfloor->ty);
    rfloor->color.r = (unsigned char)
    (rfloor->color.r * rfloor->distance_factor);
    rfloor->color.g = (unsigned char)
    (rfloor->color.g * rfloor->distance_factor);
    rfloor->color.b = (unsigned char)
    (rfloor->color.b * rfloor->distance_factor);
    put_pixel_with_flashlight(game, x, y, rfloor->color);
    rfloor->floor_x += rfloor->floor_step_x;
    rfloor->floor_y += rfloor->floor_step_y;
}

static void draw_floor_row(game_t *game, ray_floor_t *rfloor, int y)
{
    floor_init(rfloor, game, y);
    for (int x = 0; x < SCREEN_WIDTH; x++)
        draw_floor_pixel(game, rfloor, x, y);
}

void draw_floor(game_t *game)
{
    ray_floor_t *rfloor = calloc(1, sizeof(ray_floor_t));

    if (!rfloor)
        return;
    rfloor->floor_texture = game->textures->walls[6];
    if (!rfloor->floor_texture) {
        free(rfloor);
        return;
    }
    for (int y = SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT; y++)
        draw_floor_row(game, rfloor, y);
    free(rfloor);
}
