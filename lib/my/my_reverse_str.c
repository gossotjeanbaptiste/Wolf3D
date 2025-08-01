/*
** EPITECH PROJECT, 2024
** my_reverse_str
** File description:
** my_reverse_str
*/
#include "my.h"

void my_reverse_str(char *str, int len)
{
    int i;
    char temp;

    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
