/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** draw_ceiling
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static ray_ceiling_t *init_ceiling_data(game_t *game)
{
    ray_ceiling_t *ceil = malloc(sizeof(ray_ceiling_t));

    if (!ceil)
        return (NULL);
    ceil->sky = game->textures->walls[7];
    ceil->tex_width = sfImage_getSize(ceil->sky).x;
    ceil->tex_height = sfImage_getSize(ceil->sky).y;
    ceil->rotation_offset = atan2(game->dirY, game->dirX) / (2 * M_PI);
    return ceil;
}

static void init_ray_for_column(ray_ceiling_t *ceil, game_t *game, int x)
{
    ceil->camera_x = 2.0 * x / (float)SCREEN_WIDTH - 1.0;
    ceil->ray_dir_x = game->dirX + game->planeX * ceil->camera_x;
    ceil->ray_dir_y = game->dirY + game->planeY * ceil->camera_x;
}

static void calculate_pixel_position(ray_ceiling_t *ceil, int y)
{
    ceil->position_z = 0.5 * SCREEN_HEIGHT;
    ceil->row_distance = ceil->position_z / (SCREEN_HEIGHT / 2.0 - y);
    ceil->floor_x = ceil->row_distance * ceil->ray_dir_x + ceil->game_pos_x;
    ceil->floor_y = ceil->row_distance * ceil->ray_dir_y + ceil->game_pos_y;
}

static void calculate_texture_coordinates(ray_ceiling_t *ceil)
{
    ceil->tex_x = fmodf(ceil->floor_x + ceil->rotation_offset, 1.0) *
        ceil->tex_width;
    ceil->tex_y = fmodf(ceil->floor_y, 1.0) * ceil->tex_height;
    ceil->tex_x = fmodf(ceil->tex_x + ceil->tex_width, ceil->tex_width);
    ceil->tex_y = fmodf(ceil->tex_y + ceil->tex_height, ceil->tex_height);
}

static void apply_fog_effect(ray_ceiling_t *ceil)
{
    ceil->fog_factor = 1.0 - (ceil->row_distance / 20.0);
    if (ceil->fog_factor < 0.0)
        ceil->fog_factor = 0.0;
    ceil->color.r = (sfUint8)(ceil->color.r * ceil->fog_factor);
    ceil->color.g = (sfUint8)(ceil->color.g * ceil->fog_factor);
    ceil->color.b = (sfUint8)(ceil->color.b * ceil->fog_factor);
}

static void draw_ceiling_pixel(ray_ceiling_t *ceil, game_t *game, int x, int y)
{
    calculate_pixel_position(ceil, y);
    calculate_texture_coordinates(ceil);
    ceil->color = sfImage_getPixel(ceil->sky,
        (int)ceil->tex_x, (int)ceil->tex_y);
    apply_fog_effect(ceil);
    put_pixel_with_flashlight(game, x, y, ceil->color);
}

static void draw_ceiling_column(ray_ceiling_t *ceil, game_t *game, int x)
{
    init_ray_for_column(ceil, game, x);
    for (int y = 0; y < SCREEN_HEIGHT / 2; y++) {
        draw_ceiling_pixel(ceil, game, x, y);
    }
}

void draw_ceiling(game_t *game)
{
    ray_ceiling_t *ceil = init_ceiling_data(game);

    if (!ceil)
        return;
    ceil->game_pos_x = game->posX;
    ceil->game_pos_y = game->posY;
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        draw_ceiling_column(ceil, game, x);
    }
    free(ceil);
}
