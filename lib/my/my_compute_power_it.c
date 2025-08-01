/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** return the power n of a number x
*/
#include "my.h"

static int at_power(int n, int p)
{
    int resultat = n;

    for (int i = 1; i < p; i++) {
        resultat *= n;
        if (n > INT_MAX)
            return 0;
    }
    return resultat;
}

int my_compute_power_it(int nb, int p)
{
    int resultat;

    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;
    else
        resultat = at_power(nb, p);
    return resultat;
}
