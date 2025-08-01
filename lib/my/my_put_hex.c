/*
** EPITECH PROJECT, 2025
** Epi-Template-C
** File description:
** my_put_hex
*/

#include "my.h"


static void annexe_my_put_hex(int remainder, int is_upper, int nb, int res)
{
    char digit;

    remainder = nb % 16;
    if (remainder > 9) {
        digit = remainder + (is_upper ? 'A' - 10 : 'a' - 10);
    } else {
        digit = remainder + '0';
    }
    my_putchar(digit);
    res += 1;
}

int my_put_hex(unsigned int nb, int is_upper, int precision)
{
    int res = 0;
    int remainder = 0;
    char digit;

    if (nb >= 16) {
        res += my_put_hex(nb / 16, is_upper, precision);
        remainder = nb % 16;
        if (remainder > 9) {
            digit = remainder + (is_upper ? 'A' - 10 : 'a' - 10);
        } else {
            digit = remainder + '0';
        }
        my_putchar(digit);
        res += 1;
    } else {
        annexe_my_put_hex(remainder, is_upper, nb, res);
    }
    return res;
}
