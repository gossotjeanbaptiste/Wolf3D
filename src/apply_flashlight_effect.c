/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** apply_flashlight_effect
*/

#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/struct_fb.h"

static void compute_flashlight_effect
(app_flash_t *app_flash, int x, int y, game_t *game)
{
    app_flash->center_x = SCREEN_WIDTH / 2.0f;
    app_flash->dx = fabsf(x - app_flash->center_x) / app_flash->center_x;
    app_flash->center_y = SCREEN_HEIGHT / 2.0f;
    app_flash->dy = (y - app_flash->center_y) / app_flash->center_y;
    app_flash->h_factor =
    1.0f - powf(app_flash->dx / game->flashlight->radius, 1.2f);
    app_flash->v_factor =
    1.0f - powf(fabsf(app_flash->dy) / 0.8f, 0.8f);
    app_flash->light_factor =
    app_flash->h_factor * app_flash->v_factor * game->flashlight->intensity;
    app_flash->light_factor =
    fmaxf(0.2f, fminf(app_flash->light_factor, 1.0f));
}

void apply_flashlight_effect(game_t *game, int x, int y, sfColor *color)
{
    app_flash_t app_flash;

    if (!game->flashlight->enabled) {
        color->r = (sfUint8)(color->r * 0.2f);
        color->g = (sfUint8)(color->g * 0.2f);
        color->b = (sfUint8)(color->b * 0.2f);
        return;
    }
    compute_flashlight_effect(&app_flash, x, y, game);
    color->r = (sfUint8)(color->r * app_flash.light_factor);
    color->g = (sfUint8)(color->g * app_flash.light_factor);
    color->b = (sfUint8)(color->b * app_flash.light_factor);
}
