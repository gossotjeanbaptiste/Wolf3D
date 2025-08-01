/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** display if an integer is positive or negative
*/
#include "my.h"

void my_isneg(int n)
{
    if (n < 0)
        mini_printf("N\n");
    else
        mini_printf("P\n");
}
