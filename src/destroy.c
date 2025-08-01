/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** destroy
*/

#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/struct_fb.h"

static void destroy_menu(menu_t menu)
{
    if (menu.button1.sprite)
        sfSprite_destroy(menu.button1.sprite);
    if (menu.button1.texture)
        sfTexture_destroy(menu.button1.texture);
    if (menu.button2.sprite)
        sfSprite_destroy(menu.button2.sprite);
    if (menu.button2.texture)
        sfTexture_destroy(menu.button2.texture);
    if (menu.button3.sprite)
        sfSprite_destroy(menu.button3.sprite);
    if (menu.button3.texture)
        sfTexture_destroy(menu.button3.texture);
    if (menu.bg_menu.sprite)
        sfSprite_destroy(menu.bg_menu.sprite);
    if (menu.bg_menu.texture)
        sfTexture_destroy(menu.bg_menu.texture);
    if (menu.title)
        sfText_destroy(menu.title);
}


void destroy_background(background_t *bg)
{
    if (bg->texture) {
        sfTexture_destroy(bg->texture);
        bg->texture = NULL;
    }
    if (bg->sprite) {
        sfSprite_destroy(bg->sprite);
        bg->sprite = NULL;
    }
}

static void free_map(char **map, int height)
{
    for (int i = 0; i < height; i++)
        free(map[i]);
    free(map);
}

static void destroy_textures(textures_t *tex)
{
    for (int i = 0; i < TEXTURE_COUNT; i++) {
        if (tex->walls[i])
            sfImage_destroy(tex->walls[i]);
    }
    free(tex);
}

static void destroy_sounds(sounds_t *sounds)
{
    if (!sounds)
        return;
    for (int i = 0; i < 1; i++) {
        if (sounds->music[i])
            sfMusic_destroy(sounds->music[i]);
    }
    free(sounds->music);
    free(sounds);
}

void destroy_game(game_t *game, ray_t *ray)
{
    sfRenderWindow_destroy(game->window);
    destroy_textures(game->textures);
    destroy_sounds(game->sounds);
    free_weapon(game);
    free(game->hud);
    sfTexture_destroy(game->screen_texture);
    sfSprite_destroy(game->screen_sprite);
    free(game->framebuffer);
    free(ray);
    free_map(game->mapping->map, game->mapping->height);
    free(game->mapping);
    free_entities(game);
    destroy_menu(game->main_menu);
    destroy_menu(game->setting);
    //destroy_menu(game->end_menu);
    free(game);
}
