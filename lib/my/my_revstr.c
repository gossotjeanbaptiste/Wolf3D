/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** reverse a string
*/
#include "my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str);
    char temp_1;
    char temp_2;

    for (int j = 0; j < (i / 2); j++) {
        temp_1 = str[j];
        temp_2 = str[i - j - 1];
        str[j] = temp_2;
        str[i - j - 1] = temp_1;
    }
    return str;
}
