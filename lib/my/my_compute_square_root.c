/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** return the squareroot of an integer
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    int resultat = 0;
    int i = 0;
    int add = 0;

    for (i = 1; resultat < nb; i++) {
        add = 2 * i - 1;
        resultat += add;
    }
    i--;
    if (my_compute_power_it(i, 2) != nb) {
        i = 0;
    }
    return i;
}
