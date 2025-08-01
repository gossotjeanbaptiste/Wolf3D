/*
** EPITECH PROJECT, 2024
** Project-my_hunter
** File description:
** randint
*/
#include "my.h"

int randint(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}
