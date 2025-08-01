/*
** EPITECH PROJECT, 2025
** Epi-Graphical-C-Template
** File description:
** wolf3d
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"


void draw_title(sfRenderWindow *window, char *name)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/Pixel_Digivolve.otf");
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfText *title = sfText_create();
    unsigned int character_size = window_size.y / 5;
    sfFloatRect text_bounds;

    sfText_setString(title, name);
    sfText_setFont(title, font);
    sfText_setCharacterSize(title, character_size);
    text_bounds = sfText_getLocalBounds(title);
    sfText_setOrigin(title, (sfVector2f){
        text_bounds.left + text_bounds.width / 2.0f,
        text_bounds.top + text_bounds.height / 2.0f
    });
    sfText_setPosition(title, (sfVector2f){
        window_size.x / 2.0f,
        window_size.y * 0.15f
    });
    sfRenderWindow_drawText(window, title, NULL);
    sfText_destroy(title);
    sfFont_destroy(font);
}

void init_main_menu(game_t *game)
{
    game->main_menu.title = sfText_create();
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    init_background(&game->main_menu.bg_menu,
        "assets/texture/background.png", game->window);
    init_button(&game->main_menu.button1,
        "assets/texture/button_play.png", game->window, 64);
    game->main_menu.button1.pos_x = 2.0f;
    game->main_menu.button1.pos_y = 2.0f;
    adjust_button_position(game->window, &game->main_menu.button1);
    init_button(&game->main_menu.button2,
        "assets/texture/button_quit.png", game->window, 64);
    game->main_menu.button2.pos_x = 2.0f;
    game->main_menu.button2.pos_y = 1.3f;
    adjust_button_position(game->window, &game->main_menu.button2);
    init_button(&game->main_menu.button3,
        "assets/texture/button_settings.png", game->window, 32);
    game->main_menu.button3.pos_x = 1.3f;
    game->main_menu.button3.pos_y = 1.3f;
    adjust_button_position(game->window, &game->main_menu.button3);
}

void main_menu(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        event_main_menu(game);
    }
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_clear(game->window, sfBlack);
    update_button_state(&game->main_menu.button1, game->window, game->event);
    update_button_state(&game->main_menu.button2, game->window, game->event);
    update_button_state(&game->main_menu.button3, game->window, game->event);
    event_main_menu_buttons(game);
    sfRenderWindow_drawSprite(game->window,
        game->main_menu.bg_menu.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
        game->main_menu.button1.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
        game->main_menu.button2.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
        game->main_menu.button3.sprite, NULL);
    draw_title(game->window, "Wolf3D");
    sfRenderWindow_display(game->window);
}
