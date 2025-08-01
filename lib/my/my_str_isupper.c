/*
** EPITECH PROJECT, 2024
** my_str_isupper
** File description:
** verify is a str contains only uppercase letter
*/
#include "my.h"

int my_str_isupper(char const *str)
{
    int i = 0;
    int is_upper = 1;

    if (is_empty(str) == 1)
        return 1;
    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'Z') {
            is_upper = 0;
            return 0;
        }
    }
    return is_upper;
}
