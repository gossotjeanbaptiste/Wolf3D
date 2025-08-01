/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** create_game_instance
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

void init_background(background_t *background, const char *filename,
    sfRenderWindow *window)
{
    background->texture = sfTexture_createFromFile(filename, NULL);
    if (!background->texture)
        return;
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    adjust_background(window, background);
}

void init_button(button_t *button, const char *filename,
    sfRenderWindow *window, int size)
{
    button->texture = sfTexture_createFromFile(filename, NULL);
    if (!button->texture) {
        return;
    }
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    button->rect = (sfIntRect){0, 0, size, 32};
    sfSprite_setTextureRect(button->sprite, button->rect);
    button->state = 0;
    adjust_button_position(window, button);
}
