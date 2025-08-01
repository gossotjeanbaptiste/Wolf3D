/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** display number given as parameter
*/
#include "my.h"

int my_put_nbr(int nb)
{
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    if (neg == 1) {
        my_putchar('-');
    }
    return 0;
}
