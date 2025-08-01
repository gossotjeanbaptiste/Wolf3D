/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** my_put_long
*/
#include "my.h"

int my_put_long(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_long(nb / 10);
        my_putchar(nb % 10 + '0');
    } else {
        my_putchar(nb + '0');
    }
    return (0);
}
