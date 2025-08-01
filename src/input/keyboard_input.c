/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** wolf3d
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static void key_z_pressed(game_t *game, float move_speed)
{
    double newPosX = game->posX + game->dirX * move_speed;
    double newPosY = game->posY + game->dirY * move_speed;
    int mapY = (int)game->posY;
    int mapX = (int)newPosX;

    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (mapY >= 0 && mapY < game->mapping->height &&
            mapX >= 0 && mapX < game->mapping->width &&
            is_walkable_cell(game->mapping->map[mapY][mapX])) {
        game->posX = newPosX;
        }
        mapY = (int)newPosY;
        mapX = (int)game->posX;
        if (mapY >= 0 && mapY < game->mapping->height &&
            mapX >= 0 && mapX < game->mapping->width &&
            is_walkable_cell(game->mapping->map[mapY][mapX])) {
            game->posY = newPosY;
        }
    }
}

static void key_s_pressed(game_t *game, float move_speed)
{
    double newPosX = game->posX - game->dirX * move_speed;
    double newPosY = game->posY - game->dirY * move_speed;
    int mapY = (int)game->posY;
    int mapX = (int)newPosX;

    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (mapY >= 0 && mapY < game->mapping->height &&
            mapX >= 0 && mapX < game->mapping->width &&
            is_walkable_cell(game->mapping->map[mapY][mapX])) {
            game->posX = newPosX;
        }
        mapY = (int)newPosY;
        mapX = (int)game->posX;
        if (mapY >= 0 && mapY < game->mapping->height &&
            mapX >= 0 && mapX < game->mapping->width &&
            is_walkable_cell(game->mapping->map[mapY][mapX])) {
            game->posY = newPosY;
        }
    }
}

static void key_d_pressed(game_t *game, float move_speed)
{
    double newPosX = game->posX + game->dirY * move_speed;
    double newPosY = game->posY - game->dirX * move_speed;
    int mapY = (int)game->posY;
    int mapX = (int)newPosX;

    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        if (mapY >= 0 && mapY < game->mapping->height &&
            mapX >= 0 && mapX < game->mapping->width &&
            is_walkable_cell(game->mapping->map[mapY][mapX])) {
            game->posX = newPosX;
        }
        mapY = (int)newPosY;
        mapX = (int)game->posX;
        if (mapY >= 0 && mapY < game->mapping->height &&
            mapX >= 0 && mapX < game->mapping->width &&
            is_walkable_cell(game->mapping->map[mapY][mapX])) {
            game->posY = newPosY;
        }
    }
}

static void key_q_pressed(game_t *game, float move_speed)
{
    double newPosX = game->posX - game->dirY * move_speed;
    double newPosY = game->posY + game->dirX * move_speed;
    int mapY = (int)game->posY;
    int mapX = (int)newPosX;

    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (mapY >= 0 && mapY < game->mapping->height &&
            mapX >= 0 && mapX < game->mapping->width &&
            is_walkable_cell(game->mapping->map[mapY][mapX])) {
            game->posX = newPosX;
        }
        mapY = (int)newPosY;
        mapX = (int)game->posX;
        if (mapY >= 0 && mapY < game->mapping->height &&
            mapX >= 0 && mapX < game->mapping->width &&
            is_walkable_cell(game->mapping->map[mapY][mapX])) {
            game->posY = newPosY;
        }
    }
}

static void window_resized(game_t *game)
{
    static sfBool is_fullscreen = sfFalse;
    static sfVector2u prev_size = {SCREEN_WIDTH, SCREEN_HEIGHT};
    sfVideoMode mode;

    if (sfKeyboard_isKeyPressed(sfKeyF11)) {
        sfSleep(sfSeconds(0.2f));
        is_fullscreen = !is_fullscreen;
        if (is_fullscreen) {
            prev_size = sfRenderWindow_getSize(game->window);
            mode = sfVideoMode_getDesktopMode();
            sfRenderWindow_setSize(game->window, (sfVector2u){mode.width,
                mode.height});
            sfRenderWindow_setPosition(game->window, (sfVector2i){0, 0});
            sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        } else {
            sfRenderWindow_setSize(game->window, prev_size);
            sfRenderWindow_setPosition(game->window, (sfVector2i){100, 100});
            sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        }
    }
}

static void flashlight(game_t *game)
{
    static float elapsed = 0;

    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        elapsed = sfTime_asSeconds
        (sfClock_getElapsedTime(game->flashlight->toggle_clock));
        if (elapsed > 0.3f) {
            game->flashlight->enabled = !game->flashlight->enabled;
            sfClock_restart(game->flashlight->toggle_clock);
        }
    }
}

void handle_keyboard_input(game_t *game, float move_speed, float rot_speed)
{
    key_z_pressed(game, move_speed);
    key_s_pressed(game, move_speed);
    key_d_pressed(game, move_speed);
    key_q_pressed(game, move_speed);
    handle_mouse_input(game, rot_speed);
    window_resized(game);
    flashlight(game);
    if (sfKeyboard_isKeyPressed(sfKeyF4))
        sfRenderWindow_close(game->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->precedent_gamestate = 1;
        game->gamestate = 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        sfMouse_setPositionRenderWindow((sfVector2i){SCREEN_WIDTH / 2,
            SCREEN_HEIGHT / 2}, game->window);
    }
}
