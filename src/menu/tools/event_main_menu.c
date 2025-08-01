/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** event_main_menu
*/

#include "../../../include/csfml_include.h"
#include "../../../include/my.h"
#include "../../../include/struct_fb.h"

void event_main_menu(game_t *game)
{
    sfView *view;
    if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtMouseButtonPressed)
        game->click = 1;
    if (game->event.type == sfEvtResized) {
        view = sfView_createFromRect
        ((sfFloatRect){0, 0, game->event.size.width, game->event.size.height});
        sfRenderWindow_setView(game->window, view);
        sfView_destroy(view);
        adjust_background(game->window, &game->main_menu.bg_menu);
        adjust_button_position(game->window, &game->main_menu.button1);
        adjust_button_position(game->window, &game->main_menu.button2);
        adjust_button_position(game->window, &game->main_menu.button3);
        }
}
