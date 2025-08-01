/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_textures
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

textures_t *init_textures(void)
{
    textures_t *tex = malloc(sizeof(textures_t));

    if (!tex)
        return NULL;
    tex->walls[0] = NULL;
    tex->walls[1] = sfImage_createFromFile("assets/texture/wall_1.png");
    tex->walls[2] = sfImage_createFromFile("assets/texture/wall_2.png");
    tex->walls[3] = sfImage_createFromFile("assets/texture/wall_3.png");
    tex->walls[4] = sfImage_createFromFile("assets/texture/wall_4.png");
    tex->walls[5] = sfImage_createFromFile("assets/texture/wall_5.png");
    tex->walls[6] = sfImage_createFromFile("assets/texture/wall_6.png");
    tex->walls[7] = sfImage_createFromFile("assets/texture/sky.png");
    tex->walls[8] = sfImage_createFromFile("assets/texture/wall_7.png");
    return tex;
}
