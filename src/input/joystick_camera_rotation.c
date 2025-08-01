/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** joystick_camera_rotation
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

static void camera_axis_pos(camera_t *camera, game_t *game)
{
    camera->old_dir_x = game->dirX;
    game->dirX = game->dirX * cos(-camera->smooth_rot_speed) -
        game->dirY * sin(-camera->smooth_rot_speed);
    game->dirY = camera->old_dir_x * sin(-camera->smooth_rot_speed) +
        game->dirY * cos(-camera->smooth_rot_speed);
    camera->old_plane_x = game->planeX;
    game->planeX = game->planeX * cos(-camera->smooth_rot_speed) -
        game->planeY * sin(-camera->smooth_rot_speed);
    game->planeY = camera->old_plane_x * sin(-camera->smooth_rot_speed) +
        game->planeY * cos(-camera->smooth_rot_speed);
}

static void camera_axis_neg(camera_t *camera, game_t *game)
{
    camera->old_dir_x = game->dirX;
    game->dirX = game->dirX * cos(camera->smooth_rot_speed) -
        game->dirY * sin(camera->smooth_rot_speed);
    game->dirY = camera->old_dir_x * sin(camera->smooth_rot_speed) +
        game->dirY * cos(camera->smooth_rot_speed);
    camera->old_plane_x = game->planeX;
    game->planeX = game->planeX * cos(camera->smooth_rot_speed) -
        game->planeY * sin(camera->smooth_rot_speed);
    game->planeY = camera->old_plane_x * sin(camera->smooth_rot_speed) +
        game->planeY * cos(camera->smooth_rot_speed);
}

void joystick_camera_rotation(game_t *game, float rot_speed)
{
    camera_t camera;

    camera.axis_position = sfJoystick_getAxisPosition(0, sfJoystickU);
    if (fabsf(camera.axis_position) > 10.0f) {
        camera.intensity = fmin(1.0f, fabsf(camera.axis_position) / 100.0f);
        camera.smooth_rot_speed = rot_speed * camera.intensity;
        if (camera.axis_position > 0) {
            camera_axis_pos(&camera, game);
        } else {
            camera_axis_neg(&camera, game);
        }
    }
}
