/*
** EPITECH PROJECT, 2025
** my header files
** File description:
** declaration of all functions
*/

#ifndef FRAMEBUFF_H
    #define FRAMEBUFF_H
    #include <math.h>
    #include <stdbool.h>
    #include "csfml_include.h"
    #include "my.h"
    #include "ansi_color_code.h"
typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    unsigned char *pixels;
} framebuffer_t;

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,
    unsigned int y, sfColor color);
void framebuffer_destroy(framebuffer_t *framebuffer);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
#endif /* !FRAMEBUFF_H */

#ifndef WOLF_3D_H
    #define WOLF_3D_H
    #define SCREEN_WIDTH 640
    #define SCREEN_HEIGHT 480
    #define TEX_WIDTH 128
    #define TEX_HEIGHT 128
    #define PIXELS (SCREEN_WIDTH * SCREEN_HEIGHT * 4)
    #define TEXTURE_COUNT 9

typedef struct textures_s {
    sfImage *walls[TEXTURE_COUNT];
    int wall_type;
    int tex_x;
    sfImage *current_texture;
}textures_t;

typedef struct sounds_s {
    sfMusic **music;
    int play;
} sounds_t;

typedef struct map_s {
    int width;
    int height;
    char **map;
} map_t;

typedef struct background {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
} background_t;

typedef struct button {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
    sfVector2f scale;
    int state;
    float pos_x;
    float pos_y;
} button_t;

typedef struct menu {
    button_t button1;
    button_t button2;
    button_t button3;
    sfText *title;
    sfVector2f pos_title;
    background_t bg_menu;
    int touch;
} menu_t;

typedef struct hud_s {
    sfTexture *gun_texture;
    sfSoundBuffer *shot_buffer;
    sfSound *shot;
    sfSprite *gun_sprite;
    sfClock *gun_clock;
    int gun_frame;
    int gun_max_frame;
    int gun_animate;
} hud_t;

typedef struct flashlight_s {
    bool enabled;
    float intensity;
    float radius;
    float angle;
    float falloff;
    sfClock *toggle_clock;
} flashlight_t;

typedef struct app_flash_s {
    float center_x;
    float center_y;
    float dx;
    float dy;
    float h_factor;
    float v_factor;
    float light_factor;
} app_flash_t;

typedef struct entity_s {
    double x;
    double y;
    sfTexture *texture;
    sfImage *image;
    int is_dead;
    int death_anim_frame;
    sfClock *death_clock;
} entity_t;

typedef struct game_s {
    sfView *view;
    sfRenderWindow *window;
    sfEvent event;
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    map_t *mapping;
    int previous_map;
    textures_t *textures;
    sounds_t *sounds;
    sfUint8 *framebuffer;
    sfTexture *screen_texture;
    sfSprite *screen_sprite;
    int gamestate;
    int precedent_gamestate;
    int click;
    menu_t main_menu;
    menu_t end_menu;
    menu_t setting;
    hud_t *hud;
    flashlight_t *flashlight;
    entity_t **entities;
    int entity_count;
    float *zbuffer;
} game_t;

typedef struct ray_s {
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    int step_x;
    int step_y;
    int hit;
    int side;
    int line_height;
    int draw_start;
    int draw_end;
} ray_t;

typedef struct ray_floor_s {
    sfImage *floor_texture;
    sfColor color;
    float ray_dix_x0;
    float ray_dix_y0;
    float ray_dix_x1;
    float ray_dix_y1;
    int vertical_pos;
    float pos_z;
    float row_distance;
    float floor_step_x;
    float floor_step_y;
    float floor_x;
    float floor_y;
    int tx;
    int ty;
    float distance_factor;
} ray_floor_t;

typedef struct ray_ceiling_s {
    sfImage *sky;
    sfColor color;
    int tex_width;
    int tex_height;
    float rotation_offset;
    float camera_x;
    float ray_dir_x;
    float ray_dir_y;
    float position_z;
    float row_distance;
    float floor_x;
    float floor_y;
    float tex_x;
    float tex_y;
    float fog_factor;
    int pixel_pos;
    float game_pos_x;
    float game_pos_y;
} ray_ceiling_t;

typedef struct move_s {
    float axis_position;
    float intensity;
    float smooth_move_speed;
    float newPosX;
    float newPosY;
    bool canMoveX;
    bool canMoveY;
} move_t;

typedef struct camera_s {
    double old_dir_x;
    double old_plane_x;
    float axis_position;
    float intensity;
    float smooth_rot_speed;
} camera_t;

#endif /* !WOLF_3D_H */
