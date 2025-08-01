/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** verify is there's only lowercase in a str
*/
#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;
    int is_lower_or_not = 1;

    if (is_empty(str) == 1)
        return 1;
    while (str[i] != '\0') {
        if (str[i] < 'a' || str[i] > 'z') {
            is_lower_or_not = 0;
            return is_lower_or_not;
        }
    }
    return is_lower_or_not;
}
