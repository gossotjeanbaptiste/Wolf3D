/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** display each char of a string
*/
#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}
