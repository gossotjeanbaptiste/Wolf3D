/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** wolf3d
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static void initialize_mouse_cursor(sfRenderWindow *window,
    float *last_mouse_x, sfBool *mouse_hidden)
{
    sfVector2i center;

    if (!(*mouse_hidden)) {
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        *mouse_hidden = sfTrue;
    }
    if (*last_mouse_x == -1) {
        *last_mouse_x = (float)(SCREEN_WIDTH / 2);
        center.x = SCREEN_WIDTH / 2;
        center.y = SCREEN_HEIGHT / 2;
        sfMouse_setPositionRenderWindow(center, window);
    }
}

static void rotate_player(game_t *game, float rotation_amount)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = game->dirX;
    game->dirX = game->dirX * cos(rotation_amount) -
        game->dirY * sin(rotation_amount);
    game->dirY = old_dir_x * sin(rotation_amount) +
        game->dirY * cos(rotation_amount);
    old_plane_x = game->planeX;
    game->planeX = game->planeX * cos(rotation_amount) -
        game->planeY * sin(rotation_amount);
    game->planeY = old_plane_x * sin(rotation_amount) +
        game->planeY * cos(rotation_amount);
}

static float get_mouse_delta(sfRenderWindow *window, float last_mouse_x)
{
    float mouse_x;

    mouse_x = (float)sfMouse_getPositionRenderWindow(window).x;
    return mouse_x - last_mouse_x;
}

static void center_mouse_position(sfRenderWindow *window, float *last_mouse_x)
{
    sfVector2i center;

    center.x = SCREEN_WIDTH / 2;
    center.y = SCREEN_HEIGHT / 2;
    sfMouse_setPositionRenderWindow(center, window);
    *last_mouse_x = (float)center.x;
}

void handle_mouse_input(game_t *game, float rot_speed)
{
    static float last_mouse_x = -1;
    static sfBool mouse_hidden = sfFalse;
    float delta_x;
    float rotation_amount;

    initialize_mouse_cursor(game->window, &last_mouse_x, &mouse_hidden);
    if (last_mouse_x == -1)
        return;
    delta_x = get_mouse_delta(game->window, last_mouse_x);
    if (delta_x != 0 && sfRenderWindow_hasFocus(game->window)) {
        rotation_amount = -delta_x * rot_speed * 0.01f;
        rotate_player(game, rotation_amount);
        center_mouse_position(game->window, &last_mouse_x);
    } else
        last_mouse_x =
        (float)sfMouse_getPositionRenderWindow(game->window).x;
}
