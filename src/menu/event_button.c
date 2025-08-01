/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** pass_to_game
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

int event_main_menu_buttons(game_t *game)
{
    if (game->main_menu.button1.state == 2 && game->click == 1) {
        game->precedent_gamestate = 0;
        game->gamestate = 1;
        usleep(150000);
        flush_sfml_events(game);
        game->click = 0;
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        return 1;
    }
    if (game->main_menu.button2.state == 2 && game->click == 1) {
        sfRenderWindow_close(game->window);
        game->click = 0;
        return 1;
    }
    if (game->main_menu.button3.state == 2 && game->click == 1) {
        game->precedent_gamestate = 0;
        game->gamestate = 3;
        flush_sfml_events(game);
        game->click = 0;
        return 1;
    }
    return 0;
}

int event_settings_buttons_bis(game_t *game)
{
    if (game->setting.button3.state == 2 && game->click == 1) {
        if (game->sounds->play == 0) {
            game->sounds->play = 1;
            sfMusic_stop(game->sounds->music[0]);
            game->click = 0;
            return 1;
        }
        if (game->sounds->play == 1) {
            game->sounds->play = 0;
            sfMusic_setLoop(game->sounds->music[0], sfTrue);
            sfMusic_setVolume(game->sounds->music[0], 50);
            sfMusic_play(game->sounds->music[0]);
            game->click = 0;
            return 1;
        }
    }
    return 0;
}

int event_settings_buttons(game_t *game)
{
    if (game->setting.button1.state == 2 && game->click == 1) {
        game->gamestate = game->precedent_gamestate;
        game->precedent_gamestate = 3;
        flush_sfml_events(game);
        game->click = 0;
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        return 1;
    }
    if (game->setting.button2.state == 2 && game->click == 1) {
        game->gamestate = 0;
        game->precedent_gamestate = 3;
        flush_sfml_events(game);
        return 1;
    }
    return event_settings_buttons_bis(game);
}
