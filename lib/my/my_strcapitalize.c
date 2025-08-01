/*
** EPITECH PROJECT, 2024
** my_strcapitalize
** File description:
** put every first letter of a word in a str in uppercase
*/
#include "my.h"

char *my_strcapitalize(char *str)
{
    int i = 1;

    str[0] -= 32;
    while (str[i] != '\0') {
        if ((str[i - 1] == ' ' && str[i] >= 'a') || str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return str;
}
