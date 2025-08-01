/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** concatenante n char in src string
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0') {
        a++;
    }
    while (src[b] != '\0' && b < n) {
        dest[a + b] = src[b];
        b++;
    }
    dest[a + b] = '\0';
    return dest;
}
