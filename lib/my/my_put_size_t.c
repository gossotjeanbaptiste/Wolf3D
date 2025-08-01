/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** my_put_size_t
*/
#include "my.h"
#include <stddef.h>

int my_put_size_t(size_t nb)
{
    int count = 0;

    if (nb >= 10) {
        count += my_put_size_t(nb / 10);
        count += my_put_size_t(nb % 10);
    } else {
        my_putchar(nb + '0');
        count++;
    }
    return count;
}
