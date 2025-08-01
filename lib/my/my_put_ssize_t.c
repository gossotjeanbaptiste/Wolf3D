/*
** EPITECH PROJECT, 2025
** Epi-Template-C
** File description:
** my_put_ssize_t
*/

#include "my.h"

int my_put_ssize_t(ssize_t nb)
{
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        count++;
    }
    if (nb >= 10) {
        count += my_put_ssize_t(nb / 10);
        count += my_put_ssize_t(nb % 10);
    } else {
        my_putchar(nb + '0');
        count++;
    }
    return count;
}
