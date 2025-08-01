/*
** EPITECH PROJECT, 2025
** Project-my_radar
** File description:
** my_atoi
*/
#include "my.h"

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == ' ')
        str++;
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
