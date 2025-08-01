/*
** EPITECH PROJECT, 2024
** Bootstrap-My_radar
** File description:
** swap_index
*/

void swap_index(char *result, int index, int i)
{
    char temp;

    temp = result[i];
    result[i] = result[index - i - 1];
    result[index - i - 1] = temp;
}
