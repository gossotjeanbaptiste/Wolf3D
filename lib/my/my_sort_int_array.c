/*
** EPITECH PROJECT, 2024
** my_sort_int_array
** File description:
** sort an array of int
*/
#include "my.h"

static void annexe_to_my_sort_int_array(int integer1, int integer2)
{
    if (integer1 > integer2) {
        my_swap(&integer1, &integer2);
    }
}

int my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int j = 0;

    while (i < size) {
        j = i + 1;
        while (j < size) {
            annexe_to_my_sort_int_array(tab[i], tab[j]);
            j++;
        }
        i++;
    }
    return 0;
}
