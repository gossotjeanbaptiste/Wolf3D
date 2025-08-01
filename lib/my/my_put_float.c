/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
** File description:
** my_put_float
*/
#include "my.h"

static void second_my_put_float(int dec_part, double dec_multiplier,
    int precision, int current_precision)
{
    int temp = dec_part;

    while (temp < (int)dec_multiplier / 10 && current_precision < precision) {
        my_putchar('0');
        temp *= 10;
        current_precision++;
    }
    my_put_nbr(dec_part);
}

int my_put_float(double nb, int precision)
{
    int int_part = (int)nb;
    double fractional_part = nb - int_part;
    double dec_multiplier = 1.0;
    int current_precision = 0;
    int dec_part = 0;

    for (int i = 0; i < precision; i++) {
        dec_multiplier *= 10.0;
    }
    dec_part = (int)(fractional_part * dec_multiplier + 0.5);
    my_put_nbr(int_part);
    my_putchar('.');
    current_precision = dec_part == 0 ? precision : 0;
    second_my_put_float(dec_part, dec_multiplier, precision,
        current_precision);
    return 0;
}
