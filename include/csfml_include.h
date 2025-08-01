/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** csfml_include
*/

#ifndef INCLUDED_CSFML_INCLUDE_H
    #define INCLUDED_CSFML_INCLUDE_H
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Window.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "struct_fb.h"
    #include <stdbool.h>

/* Src */

void render_raycasting(game_t *game, ray_t *ray);
int wolf3d(void);
void destroy_game(game_t *game, ray_t *ray);
void destroy_background(background_t *bg);
char **load_map(const char *filename, int *width, int *height);
int is_wall(char cell);
void apply_flashlight_effect(game_t *game, int x, int y, sfColor *color);
void check_elevator(game_t *game, char *map_name, int nbr);
void flush_sfml_events(game_t *game);

/* Src -> Draw */

void draw_ceiling(game_t *game);
void draw_floor(game_t *game);
void draw_textured_column(game_t *game, ray_t *ray, int x);
void put_pixel(sfUint8 *framebuffer, int x, int y, sfColor color);
void put_pixel_with_flashlight(game_t *game, int x, int y, sfColor color);

/* Src -> Init */

void init_raycasting_vars(ray_t *ray, game_t *game, int x);
textures_t *init_textures(void);
sounds_t *init_sounds(void);
int init_game_graphics(game_t *game);
int create_game_instance(game_t **game, ray_t **ray);
void init(game_t *game);
int init_flashlight(game_t *game);

/* Src -> Input */

void handle_keyboard_input(game_t *game, float move_speed, float rot_speed);
void handle_mouse_input(game_t *game, float rot_speed);
void controller_input_handler(game_t *game, float move_speed, float rot_speed);
void joystick_camera_rotation(game_t *game, float rot_speed);
int is_walkable_cell(char cell);

/* Src -> Main_Menu */
int event_main_menu_buttons(game_t *game);
void main_menu(game_t *game);
void end_menu(game_t *game);
void settings_menu(game_t *game);
void event_main_menu(game_t *game);
void init_main_menu(game_t *game);
void update_button_state(button_t *button, sfRenderWindow *window,
    sfEvent event);
void adjust_background(sfRenderWindow *window, background_t *background);
void adjust_button_position(sfRenderWindow *window, button_t *button);
void init_button(button_t *button, const char *filename,
    sfRenderWindow *window, int size);
void init_background(background_t *background, const char *filename,
    sfRenderWindow *window);
int event_settings_buttons(game_t *game);
void draw_title(sfRenderWindow *window, char *name);
void init_settings_menu(game_t *game);

/* Src -> Weapon */

void init_weapon(game_t *game);
void update_weapon_position(game_t *game);
void update_weapon_animation(game_t *game);
void free_weapon(game_t *game);
void trigger_weapon_animation(game_t *game);

/* Src -> */
void draw_entities(game_t *game);
int init_entities_from_map(game_t *game);
void check_monster_hit(game_t *game);
void free_entities(game_t *game);
void update_monsters(game_t *game);

#endif /* !INCLUDED_CSFML_INCLUDE_H */
