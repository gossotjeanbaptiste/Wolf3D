/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_game_graphics
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

int init_game_graphics(game_t *game)
{
    game->framebuffer = malloc(SCREEN_WIDTH * SCREEN_HEIGHT * 4);
    if (!game->framebuffer) {
        fprintf(stderr,
            "Erreur d'allocation de mémoire pour le framebuffer\n");
        return 84;
    }
    game->screen_texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
    game->screen_sprite = sfSprite_create();
    sfSprite_setTexture(game->screen_sprite, game->screen_texture, sfTrue);
    return 0;
}
