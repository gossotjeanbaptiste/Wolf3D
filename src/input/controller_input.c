/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** controller_input for wolf3d
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static void move_forward(game_t *game, move_t *move)
{
    int mapY = (int)game->posY;
    int mapX = (int)move->newPosX;

    move->canMoveX = (mapY >= 0 && mapY < game->mapping->height &&
                    mapX >= 0 && mapX < game->mapping->width &&
                    is_walkable_cell(game->mapping->map[mapY][mapX]));
    mapY = (int)move->newPosY;
    mapX = (int)game->posX;
    move->canMoveY = (mapY >= 0 && mapY < game->mapping->height &&
                    mapX >= 0 && mapX < game->mapping->width &&
                    is_walkable_cell(game->mapping->map[mapY][mapX]));
    if (move->canMoveX)
        game->posX = move->newPosX;
    if (move->canMoveY)
        game->posY = move->newPosY;
}

static void joystick_move_forward(game_t *game, float move_speed)
{
    move_t move;

    move.axis_position = sfJoystick_getAxisPosition(0, sfJoystickY);
    if (move.axis_position < -10.0f) {
        move.intensity = fmin(1.0f, fabsf(move.axis_position) / 100.0f);
        move.smooth_move_speed = move_speed * move.intensity;
        move.newPosX = game->posX + game->dirX * move.smooth_move_speed;
        move.newPosY = game->posY + game->dirY * move.smooth_move_speed;
        move_forward(game, &move);
    }
}

static void move_backward(game_t *game, move_t *move)
{
    int mapY = (int)game->posY;
    int mapX = (int)move->newPosX;

    move->canMoveX = (mapY >= 0 && mapY < game->mapping->height &&
                    mapX >= 0 && mapX < game->mapping->width &&
                    is_walkable_cell(game->mapping->map[mapY][mapX]));
    mapY = (int)move->newPosY;
    mapX = (int)game->posX;
    move->canMoveY = (mapY >= 0 && mapY < game->mapping->height &&
                    mapX >= 0 && mapX < game->mapping->width &&
                    is_walkable_cell(game->mapping->map[mapY][mapX]));
    if (move->canMoveX)
        game->posX = move->newPosX;
    if (move->canMoveY)
        game->posY = move->newPosY;
}

static void joystick_move_backward(game_t *game, float move_speed)
{
    move_t move;

    move.axis_position = sfJoystick_getAxisPosition(0, sfJoystickY);
    if (move.axis_position > 10.0f) {
        move.intensity = fmin(1.0f, fabsf(move.axis_position) / 100.0f);
        move.smooth_move_speed = move_speed * move.intensity;
        move.newPosX = game->posX - game->dirX * move.smooth_move_speed;
        move.newPosY = game->posY - game->dirY * move.smooth_move_speed;
        move_backward(game, &move);
    }
}

static void strafe_left(game_t *game, move_t *move)
{
    int mapY = (int)game->posY;
    int mapX = (int)move->newPosX;

    move->canMoveX = (mapY >= 0 && mapY < game->mapping->height &&
                    mapX >= 0 && mapX < game->mapping->width &&
                    is_walkable_cell(game->mapping->map[mapY][mapX]));
    mapY = (int)move->newPosY;
    mapX = (int)game->posX;
    move->canMoveY = (mapY >= 0 && mapY < game->mapping->height &&
                    mapX >= 0 && mapX < game->mapping->width &&
                    is_walkable_cell(game->mapping->map[mapY][mapX]));
    if (move->canMoveX)
        game->posX = move->newPosX;
    if (move->canMoveY)
        game->posY = move->newPosY;
}

static void joystick_strafe_left(game_t *game, float move_speed)
{
    move_t move;

    move.axis_position = sfJoystick_getAxisPosition(0, sfJoystickX);
    if (move.axis_position < -10.0f) {
        move.intensity = fmin(1.0f, fabsf(move.axis_position) / 100.0f);
        move.smooth_move_speed = move_speed * move.intensity;
        move.newPosX = game->posX - game->dirY * move.smooth_move_speed;
        move.newPosY = game->posY + game->dirX * move.smooth_move_speed;
        strafe_left(game, &move);
    }
}

static void strafe_right(game_t *game, move_t *move)
{
    int mapY = (int)game->posY;
    int mapX = (int)move->newPosX;

    move->canMoveX = (mapY >= 0 && mapY < game->mapping->height &&
                    mapX >= 0 && mapX < game->mapping->width &&
                    is_walkable_cell(game->mapping->map[mapY][mapX]));
    mapY = (int)move->newPosY;
    mapX = (int)game->posX;
    move->canMoveY = (mapY >= 0 && mapY < game->mapping->height &&
                    mapX >= 0 && mapX < game->mapping->width &&
                    is_walkable_cell(game->mapping->map[mapY][mapX]));
    if (move->canMoveX)
        game->posX = move->newPosX;
    if (move->canMoveY)
        game->posY = move->newPosY;
}

static void joystick_strafe_right(game_t *game, float move_speed)
{
    move_t move;

    move.axis_position = sfJoystick_getAxisPosition(0, sfJoystickX);
    if (move.axis_position > 10.0f) {
        move.intensity = fmin(1.0f, fabsf(move.axis_position) / 100.0f);
        move.smooth_move_speed = move_speed * move.intensity;
        move.newPosX = game->posX + game->dirY * move.smooth_move_speed;
        move.newPosY = game->posY - game->dirX * move.smooth_move_speed;
        strafe_right(game, &move);
    }
}

static void controller_button(game_t *game)
{
    static float elapsed = 0;

    if (sfJoystick_isButtonPressed(0, 7) && game->hud->gun_animate == 0)
        trigger_weapon_animation(game);
    if (sfJoystick_isButtonPressed(0, 9)) {
        game->precedent_gamestate = 1;
        game->gamestate = 3;
    }
    if (sfJoystick_isButtonPressed(0, 3)) {
        elapsed = sfTime_asSeconds
        (sfClock_getElapsedTime(game->flashlight->toggle_clock));
        if (elapsed > 0.3f) {
            game->flashlight->enabled = !game->flashlight->enabled;
            sfClock_restart(game->flashlight->toggle_clock);
        }
    }
}

void controller_input_handler(game_t *game, float move_speed, float rot_speed)
{
    if (sfJoystick_isConnected(0)) {
        sfJoystick_update();
        joystick_move_forward(game, move_speed);
        joystick_move_backward(game, move_speed);
        joystick_strafe_left(game, move_speed);
        joystick_strafe_right(game, move_speed);
        joystick_camera_rotation(game, rot_speed);
        controller_button(game);
    }
}
