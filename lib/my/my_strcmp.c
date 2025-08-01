/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare two strings
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}
