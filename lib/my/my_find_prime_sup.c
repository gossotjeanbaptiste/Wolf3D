/*
** EPITECH PROJECT, 2024
** my_find_prime_sup.c
** File description:
** find the first prime number that's
** equals or greater to the number given
** as parameter
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    while (!my_is_prime(nb))
        nb++;
    return nb;
}
