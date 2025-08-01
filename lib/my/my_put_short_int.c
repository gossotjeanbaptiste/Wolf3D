/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** my_put_short_int
*/
#include "my.h"

int my_put_short_int(short int nb)
{
    int res = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        res = (nb % 10);
        nb = (nb - res) / 10;
        my_put_short_int(nb);
        my_putchar(res + '0');
    } else {
        my_putchar(nb + '0');
    }
    return (0);
}
