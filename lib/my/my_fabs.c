/*
** EPITECH PROJECT, 2024
** my_fabs
** File description:
** my_fabs
*/
#include "my.h"


double my_fabs(double num)
{
    if (num < 0)
        return (num * -1);
    else
        return num;
}
