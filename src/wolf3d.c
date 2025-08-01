/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** wolf3d
*/

#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/struct_fb.h"

void flush_sfml_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
    }
}


static void rescale_screen_sprite(game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfVector2f scale = {
        (float)size.x / SCREEN_WIDTH,
        (float)size.y / SCREEN_HEIGHT
    };

    sfSprite_setScale(game->screen_sprite, scale);
}

static void update_main_game_view(game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfFloatRect visibleArea = {0, 0, (float)size.x, (float)size.y};

    if (game->view)
        sfView_destroy(game->view);
    game->view = sfView_createFromRect(visibleArea);
    sfRenderWindow_setView(game->window, game->view);
}

static void event(game_t *game)
{
    sfView *view;

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtResized) {
            view = sfView_createFromRect((sfFloatRect){
                0, 0, game->event.size.width, game->event.size.height
            });
            sfRenderWindow_setView(game->window, view);
            sfView_destroy(view);
            rescale_screen_sprite(game);
        }
        if (game->event.type == sfEvtResized)
            update_weapon_position(game);
    }
}

static void game_menu(game_t *game, ray_t *ray, float wall_distance_factor)
{
    event(game);
    wall_distance_factor = fmin(1.5, 1.0 + (1.0 /
        (ray->perp_wall_dist + 0.5)));
    controller_input_handler(game, 0.050f * wall_distance_factor,
        0.07f * wall_distance_factor);
    handle_keyboard_input(game, 0.050f * wall_distance_factor,
        0.07f * wall_distance_factor);
    check_elevator(game,"assets/map/map2.txt", 0);
    check_elevator(game,"assets/map/map3.txt", 1);
    sfRenderWindow_clear(game->window, sfBlack);
    render_raycasting(game, ray);
    update_weapon_position(game);
    update_weapon_animation(game);
    update_monsters(game);
    sfRenderWindow_drawSprite(game->window, game->hud->gun_sprite, NULL);
    sfRenderWindow_display(game->window);
}

static void choice_menu(game_t *game, ray_t *ray, float wall_distance_factor)
{
    static int previous_state = -1;

    if (game->gamestate != previous_state) {
        if (game->gamestate == 1) {
            update_main_game_view(game);
            rescale_screen_sprite(game);
        }
        previous_state = game->gamestate;
    }
    if (game->gamestate == 0)
        main_menu(game);
    if (game->gamestate == 1) {
        flush_sfml_events(game);
        game_menu(game, ray, wall_distance_factor);
    }
    if (game->gamestate == 2)
        end_menu(game);
    if (game->gamestate == 3)
        settings_menu(game);
}

static void game_loop(game_t *game, ray_t *ray)
{
    float wall_distance_factor = 0;

    game->gamestate = 0;
    while (sfRenderWindow_isOpen(game->window)) {
        choice_menu(game, ray, wall_distance_factor);
    }
    destroy_game(game, ray);
}

int wolf3d(void)
{
    game_t *game = NULL;
    ray_t *ray = NULL;

    if (create_game_instance(&game, &ray) == 84)
        return 84;
    if (init_game_graphics(game) == 84)
        return 84;
    init(game);
    if (game->mapping->map == NULL)
        return 84;
    if (!game->sounds)
        fprintf(stderr, "Warning: Cannot initialize sounds\n");
    game->zbuffer = malloc(sizeof(float) * SCREEN_WIDTH);
    if (!game->zbuffer)
        return 84;
    init_entities_from_map(game);
    game_loop(game, ray);
    return 0;
}
