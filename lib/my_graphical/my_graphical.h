/*
** EPITECH PROJECT, 2024
** Epi-Graphical-C-Template
** File description:
** my_graphical
*/
#include "struct_fb.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef INCLUDED_MY_GRAPHICAL_H
    #define INCLUDED_MY_GRAPHICAL_H
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,
    unsigned int y, sfColor color);
void framebuffer_destroy(framebuffer_t *framebuffer);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
#endif
