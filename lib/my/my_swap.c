/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swap two int
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int temp_1 = *a;
    int temp_2 = *b;

    *b = temp_1;
    *a = temp_2;
}
