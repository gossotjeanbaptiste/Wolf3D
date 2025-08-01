/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** copy n character from src to dest
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int length_src = my_strlen(src);

    if (n > length_src) {
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
    } else {
        while (i < n) {
            dest[i] = src[i];
            i++;
        }
    }
    dest[i] = '\0';
    return dest;
}
