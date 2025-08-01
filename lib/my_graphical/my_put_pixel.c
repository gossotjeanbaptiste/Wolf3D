/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** my_put_pixel
*/

#include "my_graphical.h"
#include "struct_fb.h"
#include <SFML/Graphics.h>

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,
    unsigned int y, sfColor color)
{
    int pos = (framebuffer->width * 4 * y) + (x * 4);

    framebuffer->pixels[pos] = color.r;
    framebuffer->pixels[pos + 1] = color.g;
    framebuffer->pixels[pos + 2] = color.b;
    framebuffer->pixels[pos + 3] = color.a;
}
