/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_raycasting_variable
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static void init_raycasting_vars2(ray_t *ray, game_t *game)
{
    if (ray->ray_dir_x < 0) {
        ray->step_x = -1;
        ray->side_dist_x = (game->posX - ray->map_x) * ray->delta_dist_x;
    } else {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - game->posX) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0) {
        ray->step_y = -1;
        ray->side_dist_y = (game->posY - ray->map_y) * ray->delta_dist_y;
    } else {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - game->posY) * ray->delta_dist_y;
    }
}

void init_raycasting_vars(ray_t *ray, game_t *game, int x)
{
    ray->camera_x = 2.0 * x / (double)SCREEN_WIDTH - 1.0;
    ray->ray_dir_x = game->dirX + game->planeX * ray->camera_x;
    ray->ray_dir_y = game->dirY + game->planeY * ray->camera_x;
    ray->map_x = (int)game->posX;
    ray->map_y = (int)game->posY;
    ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
    ray->hit = 0;
    init_raycasting_vars2(ray, game);
}
