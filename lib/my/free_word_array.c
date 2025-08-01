/*
** EPITECH PROJECT, 2025
** Project-my_radar
** File description:
** free_word_array
*/

#include "my.h"

void free_word_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
