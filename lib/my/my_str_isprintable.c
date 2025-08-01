/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** verify if all char are printable
*/
#include "my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;
    int isprintable = 1;

    if (is_empty(str) == 1)
        return 1;
    while (str[i] != '\0') {
        if (str[i] <= ' ' || str[i] >= '~') {
            isprintable = 0;
            return isprintable;
        }
    }
    return isprintable;
}
