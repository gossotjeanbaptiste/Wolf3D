/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** adjust_background
*/

#include "../../../include/csfml_include.h"
#include "../../../include/my.h"
#include "../../../include/struct_fb.h"

void adjust_background(sfRenderWindow *window, background_t *background)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2u texture_size = sfTexture_getSize(background->texture);
    float scale_x = (float)window_size.x / texture_size.x;
    float scale_y = (float)window_size.y / texture_size.y;
    float scale = (scale_x < scale_y) ? scale_x : scale_y;
    float offset_x = (window_size.x - texture_size.x * scale) / 2.0f;
    float offset_y = (window_size.y - texture_size.y * scale) / 2.0f;

    background->scale = (sfVector2f){scale, scale};
    sfSprite_setScale(background->sprite, background->scale);
    sfSprite_setPosition(background->sprite, (sfVector2f){offset_x, offset_y});
}
