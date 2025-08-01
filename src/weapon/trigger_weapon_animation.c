/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** update_weapon_animation
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

void trigger_weapon_animation(game_t *game)
{
    if (game->hud->gun_animate == 0 &&
        (sfMouse_isButtonPressed(sfMouseLeft) ||
        sfJoystick_isButtonPressed(0, 7))) {
        sfSound_play(game->hud->shot);
        game->hud->gun_animate = 1;
        game->hud->gun_frame = 0;
        sfClock_restart(game->hud->gun_clock);
        check_monster_hit(game);
    } 
}
