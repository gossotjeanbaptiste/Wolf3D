/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** put_pixel
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

void put_pixel(sfUint8 *framebuffer, int x, int y, sfColor color)
{
    int index = 0;

    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
        return;
    index = (y * SCREEN_WIDTH + x) * 4;
    framebuffer[index] = color.r;
    framebuffer[index + 1] = color.g;
    framebuffer[index + 2] = color.b;
    framebuffer[index + 3] = color.a;
}

void put_pixel_with_flashlight(game_t *game, int x, int y, sfColor color)
{
    int index = 0;

    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
        return;
    apply_flashlight_effect(game, x, y, &color);
    index = (y * SCREEN_WIDTH + x) * 4;
    game->framebuffer[index] = color.r;
    game->framebuffer[index + 1] = color.g;
    game->framebuffer[index + 2] = color.b;
    game->framebuffer[index + 3] = color.a;
}
