/*
** EPITECH PROJECT, 2024
** my_str_isnum
** File description:
** verify is there only digits in a str
*/
#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;
    int isnum_or_not = 1;

    if (is_empty(str) == 1)
        return 1;
    while (str[i] != '\0') {
        if (str[i] >= '0' || str[i] <= '9')
            isnum_or_not = 1;
        else {
            isnum_or_not = 0;
            return isnum_or_not;
        }
        i++;
    }
    return isnum_or_not;
}
