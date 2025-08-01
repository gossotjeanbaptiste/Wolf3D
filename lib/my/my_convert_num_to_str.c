/*
** EPITECH PROJECT, 2024
** convert_num_to_str
** File description:
** function that converts a num to a str
*/
#include "my.h"

static int for_my_convert_num_to_str(int i, char *str)
{
    char temp;

    for (int j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    return i;
}

int my_convert_num_to_str(unsigned int num, char *str)
{
    int i = 0;

    if (num == 0) {
        str[i] = '0';
        i++;
        str[i] = '\0';
        return i;
    }
    while (num != 0) {
        str[i] = (num % 10) + '0';
        i++;
        num = num / 10;
    }
    str[i] = '\0';
    return for_my_convert_num_to_str(i, str);
}
