/*
** EPITECH PROJECT, 2024
** my_strlowcase
** File description:
** put every letter of a str in lower case
*/
#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' || str[i] <= 'Z')
            str[i] += 32;
        if (str[i] >= 'a' || str[i] <= 'z')
            str[i] = str[i];
        if (str[i] == ' ') {
            str[i] = str[i];
        }
        i++;
    }
    return str;
}
