/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** wolf3d
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

void init_settings_menu(game_t *game)
{
    game->setting.title = sfText_create();
    init_background(&game->setting.bg_menu,
        "assets/texture/background.png", game->window);
    init_button(&game->setting.button1,
        "assets/texture/button_back.png", game->window, 64);
    game->setting.button1.pos_x = 2.0f;
    game->setting.button1.pos_y = 1.5f;
    adjust_button_position(game->window, &game->setting.button1);
    init_button(&game->setting.button2,
        "assets/texture/button_main_menu.png", game->window, 96);
    game->setting.button2.pos_x = 2.0f;
    game->setting.button2.pos_y = 2.4f;
    adjust_button_position(game->window, &game->setting.button2);
    init_button(&game->setting.button3,
        "assets/texture/button_music.png", game->window, 64);
    game->setting.button3.pos_x = 2.0f;
    game->setting.button3.pos_y = 1.1f;
    adjust_button_position(game->window, &game->setting.button3);
}

void settings_loop_menu(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    adjust_background(game->window, &game->setting.bg_menu);
    adjust_button_position(game->window, &game->setting.button1);
    adjust_button_position(game->window, &game->setting.button2);
    adjust_button_position(game->window, &game->setting.button3);
    sfRenderWindow_clear(game->window, sfBlack);
    update_button_state(&game->setting.button1, game->window, game->event);
    update_button_state(&game->setting.button3, game->window, game->event);
    sfRenderWindow_drawSprite(game->window,
        game->setting.bg_menu.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
        game->setting.button1.sprite, NULL);
    if (game->precedent_gamestate != 0) {
        update_button_state(&game->setting.button2,
            game->window, game->event);
        sfRenderWindow_drawSprite(game->window,
            game->setting.button2.sprite, NULL);
    }
    sfRenderWindow_drawSprite(game->window,
        game->setting.button3.sprite, NULL);
    event_settings_buttons(game);
    draw_title(game->window, "Settings");
    sfRenderWindow_display(game->window);
}

void settings_menu(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        event_main_menu(game);
    }
    settings_loop_menu(game);
}
