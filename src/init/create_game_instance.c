/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** create_game_instance
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static void init_game_vars(game_t *game)
{
    game->window = NULL;
    game->view = NULL;
    game->event = (sfEvent){0};
    game->posX = 0;
    game->posY = 0;
    game->dirX = 0;
    game->dirY = 0;
    game->planeX = 0;
    game->planeY = 0;
    game->mapping = NULL;
    game->textures = NULL;
    game->sounds = NULL;
    game->framebuffer = malloc(PIXELS);
    if (!game->framebuffer)
        return;
    game->screen_texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->screen_texture)
        return;
    game->screen_sprite = sfSprite_create();
}

static void init_temporary_raycast(ray_t **ray)
{
    (*ray)->perp_wall_dist = 1.0;
    (*ray)->camera_x = 0;
    (*ray)->ray_dir_x = 0;
    (*ray)->ray_dir_y = 0;
    (*ray)->map_x = 0;
    (*ray)->map_y = 0;
    (*ray)->side_dist_x = 0;
    (*ray)->side_dist_y = 0;
    (*ray)->delta_dist_x = 0;
    (*ray)->delta_dist_y = 0;
    (*ray)->step_x = 0;
    (*ray)->step_y = 0;
    (*ray)->hit = 0;
    (*ray)->side = 0;
}

int create_game_instance(game_t **game, ray_t **ray)
{
    *game = malloc(sizeof(game_t));
    *ray = malloc(sizeof(ray_t));
    if (!*game || !*ray)
        return 84;
    init_game_vars(*game);
    init_temporary_raycast(ray);
    (*game)->mapping = malloc(sizeof(map_t));
    if (!(*game)->mapping)
        return 84;
    return 0;
}
