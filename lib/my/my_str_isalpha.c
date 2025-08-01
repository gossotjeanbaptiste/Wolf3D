/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** verify if a str contains only alphabetics characters
*/
#include "my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;
    int is_alpha = 1;

    if (is_empty(str) == 1)
        return 1;
    while (str[i] != '\0') {
        if ((str[i] >= 'a' || str[i] <= 'z'))
            is_alpha = 1;
        if ((str[i] >= 'A' || str[i] <= 'Z'))
            is_alpha = 1;
        else {
            is_alpha = 0;
            return is_alpha;
        }
        i++;
    }
    return is_alpha;
}
