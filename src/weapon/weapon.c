/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** put_pixel
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

void free_weapon(game_t *game)
{
    if (game->hud->gun_sprite)
        sfSprite_destroy(game->hud->gun_sprite);
    if (game->hud->gun_texture)
        sfTexture_destroy(game->hud->gun_texture);
    if (game->hud->gun_clock)
        sfClock_destroy(game->hud->gun_clock);
    if (game->hud->shot)
        sfSound_destroy(game->hud->shot);
    if (game->hud->shot_buffer)
        sfSoundBuffer_destroy(game->hud->shot_buffer);
}

void update_weapon_animation(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->hud->gun_clock);
    float seconds = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(game->hud->gun_sprite);

    trigger_weapon_animation(game);
    if (game->hud->gun_animate == 1 && seconds > 0.1f) {
        game->hud->gun_frame++;
        if (game->hud->gun_frame >= game->hud->gun_max_frame) {
            game->hud->gun_frame = 0;
            game->hud->gun_animate = 0;
        }
        rect.left = game->hud->gun_frame * rect.width;
        sfSprite_setTextureRect(game->hud->gun_sprite, rect);
        sfClock_restart(game->hud->gun_clock);
    }
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}

void update_weapon_position(game_t *game)
{
    sfVector2u win = sfRenderWindow_getSize(game->window);
    sfIntRect rect = sfSprite_getTextureRect(game->hud->gun_sprite);
    float desired_width = win.x * 0.45f;
    float scale_x = desired_width / rect.width;
    float scale_y = scale_x;
    sfVector2f position;

    sfSprite_setScale(game->hud->gun_sprite, (sfVector2f){scale_x, scale_y});
    position.x = win.x - (rect.width * scale_x) / 0.75f;
    position.y = win.y - (rect.height * scale_y) / 1.1f;
    sfSprite_setPosition(game->hud->gun_sprite, position);
}

static int init_sound_weapons(game_t *game)
{
    game->hud->shot_buffer =
    sfSoundBuffer_createFromFile("assets/music/shot.ogg");
    if (!game->hud->shot_buffer)
        return 84;
    game->hud->shot = sfSound_create();
    if (!game->hud->shot)
        return 84;
    sfSound_setBuffer(game->hud->shot, game->hud->shot_buffer);
    sfSound_setVolume(game->hud->shot, 100.0f);
    return 0;
}

void init_weapon(game_t *game)
{
    sfIntRect rect = {0, 0, 160, 128};

    game->hud = malloc(sizeof(hud_t));
    if (!game->hud)
        return;
    game->hud->gun_texture =
        sfTexture_createFromFile("assets/texture/weapon.png", NULL);
    if (!game->hud->gun_texture)
        return;
    game->hud->gun_sprite = sfSprite_create();
    if (!game->hud->gun_sprite)
        return;
    init_sound_weapons(game);
    sfSprite_setTexture(game->hud->gun_sprite, game->hud->gun_texture, sfTrue);
    sfSprite_setTextureRect(game->hud->gun_sprite, rect);
    game->hud->gun_clock = sfClock_create();
    game->hud->gun_frame = 0;
    game->hud->gun_max_frame = 3;
    game->hud->gun_animate = 0;
    update_weapon_position(game);
}
