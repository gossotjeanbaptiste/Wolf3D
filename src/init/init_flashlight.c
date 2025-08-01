/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_flashlight
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

int init_flashlight(game_t *game)
{
    game->flashlight = malloc(sizeof(flashlight_t));
    if (!game->flashlight)
        return 84;
    game->flashlight->enabled = false;
    game->flashlight->intensity = 1.2f;
    game->flashlight->radius = 1.0f;
    game->flashlight->angle = 0.5f;
    game->flashlight->falloff = 1.5f;
    game->flashlight->toggle_clock = sfClock_create();
    return 0;
}
