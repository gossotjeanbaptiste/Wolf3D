/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** update_button_state
*/

#include "../../../include/csfml_include.h"
#include "../../../include/my.h"
#include "../../../include/struct_fb.h"

void update_button_state(button_t *button, sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->sprite);
    sfVector2f mouse_world_pos = sfRenderWindow_mapPixelToCoords(window, mouse_pos, NULL);
    sfVector2u size_button = sfTexture_getSize(button->texture);
    int texture_size_rect = size_button.x / 3;

    if (sfFloatRect_contains(&bounds, mouse_world_pos.x, mouse_world_pos.y)) {
        if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft) {
            button->state = 2;
            button->rect.left = texture_size_rect * 2;
        } else {
            button->state = 1; // survol
            button->rect.left = texture_size_rect;
        }
    } else {
        button->state = 0;
        button->rect.left = 0;
    }
    sfSprite_setTextureRect(button->sprite, button->rect);
}
