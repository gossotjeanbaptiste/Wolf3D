/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** init_sounds
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

sounds_t *init_sounds(void)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    if (!sounds)
        return NULL;
    sounds->music = malloc(sizeof(sfMusic*) * 1);
    if (!sounds->music) {
        free(sounds);
        return NULL;
    }
    sounds->music[0] = sfMusic_createFromFile("assets/music/music.ogg");
    if (!sounds->music[0]) {
        free(sounds->music);
        free(sounds);
        return NULL;
    }
    sounds->play = 0;
    sfMusic_setLoop(sounds->music[0], sfTrue);
    sfMusic_setVolume(sounds->music[0], 25);
    sfMusic_play(sounds->music[0]);
    return sounds;
}
