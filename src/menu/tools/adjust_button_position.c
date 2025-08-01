/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** adjust_button_position
*/

#include "../../../include/csfml_include.h"
#include "../../../include/my.h"
#include "../../../include/struct_fb.h"

void adjust_button_position(sfRenderWindow *window, button_t *button)
{
    sfVector2f scaled_button_size;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f button_size = {
        (float)button->rect.width,
        (float)button->rect.height
    };
    float desired_button_height = window_size.y * 0.2f;
    float scale_factor = desired_button_height / button_size.y;

    button->scale = (sfVector2f){scale_factor, scale_factor};
    sfSprite_setScale(button->sprite, button->scale);
    scaled_button_size.x = button_size.x * scale_factor;
    scaled_button_size.y = button_size.y * scale_factor;
    button->position.x = (window_size.x -
        scaled_button_size.x) / button->pos_x;
    button->position.y = (window_size.y -
        scaled_button_size.y) / button->pos_y;
    sfSprite_setPosition(button->sprite, button->position);
}
