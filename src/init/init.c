/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static void init_variables(game_t *game)
{
    game->posX = 3.0;
    game->posY = 2.0;
    game->dirX = -1.0;
    game->dirY = 0.0;
    game->planeX = 0.0;
    game->planeY = 0.66;
    game->mapping->width = 0;
    game->mapping->height = 0;
}

static void init_screen(game_t *game, int width, int height, const char *name)
{
    sfVideoMode mode = {width, height, 0};

    game->window = sfRenderWindow_create(mode, name,
        sfResize | sfClose, NULL);
}

void init(game_t *game)
{
    init_variables(game);
    init_screen(game, SCREEN_WIDTH, SCREEN_HEIGHT, "Wolf3D");
    init_weapon(game);
    init_flashlight(game);
    game->mapping->map = load_map("assets/map/map.txt",
        &game->mapping->width, &game->mapping->height);
    game->previous_map = 0;
    game->textures = init_textures();
    game->sounds = init_sounds();
    init_main_menu(game);
    init_settings_menu(game);
}
