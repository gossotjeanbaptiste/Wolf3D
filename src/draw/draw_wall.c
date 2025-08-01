/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** wolf3d
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static int get_tex_x(ray_t *ray, game_t *game)
{
    int tex_x = 0;
    double wall_x = (ray->side == 0)
        ? game->posY + ray->perp_wall_dist * ray->ray_dir_y
        : game->posX + ray->perp_wall_dist * ray->ray_dir_x;

    wall_x -= floor(wall_x);
    tex_x = (int)(wall_x * TEX_WIDTH);
    if (tex_x < 0)
        tex_x = 0;
    if (tex_x >= TEX_WIDTH)
        tex_x = TEX_WIDTH - 1;
    if (ray->side == 0 && ray->ray_dir_x > 0)
        tex_x = TEX_WIDTH - tex_x - 1;
    if (ray->side == 1 && ray->ray_dir_y < 0)
        tex_x = TEX_WIDTH - tex_x - 1;
    return tex_x;
}

static int get_tex_y(ray_t *ray, int y)
{
    int d = y * 256 - SCREEN_HEIGHT * 128 + ray->line_height * 128;
    int tex_y = ((d * TEX_HEIGHT) / ray->line_height) / 256;

    if (tex_y < 0)
        tex_y = 0;
    if (tex_y >= TEX_HEIGHT)
        tex_y = TEX_HEIGHT - 1;
    return tex_y;
}

static int set_texture_data(game_t *game, ray_t *ray)
{
    char cell;
    int wall_type;
    sfImage *tex;

    if (ray->map_y < 0 || ray->map_y >= game->mapping->height ||
        ray->map_x < 0 || ray->map_x >= game->mapping->width)
        return -1;
    cell = game->mapping->map[ray->map_y][ray->map_x];
    if (!is_wall(cell))
        return -1;
    wall_type = cell - '1';
    if (wall_type < 0 || wall_type >= TEXTURE_COUNT)
        return -1;
    tex = game->textures->walls[wall_type];
    if (!tex)
        return -1;
    game->textures->wall_type = wall_type;
    game->textures->current_texture = tex;
    game->textures->tex_x = get_tex_x(ray, game);
    return 0;
}

static void draw_column_loop(game_t *game, ray_t *ray, int x)
{
    int y;
    int tex_y;
    sfColor color;
    int tex_x = game->textures->tex_x;

    for (y = ray->draw_start; y < ray->draw_end; y++) {
        tex_y = get_tex_y(ray, y);
        color = sfImage_getPixel(game->textures->current_texture,
            tex_x, tex_y);
        if (ray->side == 1) {
            color.r *= 0.6;
            color.g *= 0.6;
            color.b *= 0.6;
        }
        put_pixel_with_flashlight(game, x, y, color);
    }
}

void draw_textured_column(game_t *game, ray_t *ray, int x)
{
    if (set_texture_data(game, ray) == -1)
        return;
    draw_column_loop(game, ray, x);
}
