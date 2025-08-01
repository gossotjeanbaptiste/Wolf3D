/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** reproduce the usage of strdup function
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *str)
{
    size_t len = my_strlen(str) + 1;
    char *new_str = (char *)malloc(len);

    if (new_str == NULL)
        return NULL;
    my_strcpy(new_str, str);
    return new_str;
}
