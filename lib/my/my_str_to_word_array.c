/*
** EPITECH PROJECT, 2025
** Project-my_radar
** File description:
** my_str_to_word_array
*/

#include "my.h"

static int number_word(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != ' ' && str[i] != '\t') &&
            (str[i + 1] == ' ' || str[i + 1] == '\t'
            || str[i + 1] == '\0'))
            count++;
    }
    return (count);
}

static char **allocate_tab(char *str)
{
    char **tab = malloc(sizeof(char *) * (number_word(str) + 1));

    if (!tab)
        return NULL;
    for (int i = 0; i < number_word(str); i++) {
        tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
        if (!tab[i])
            return NULL;
    }
    return tab;
}

static void put_in_array(char *str, char **tab, int k)
{
    int j = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        j = 0;
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
            i++;
            j++;
            tab[k][j] = str[i];
        }
        k++;
        tab[k][j] = '\0';
    }
}

char **my_str_to_word_array(char *str)
{
    char **tab = allocate_tab(str);
    int k = 0;

    if (!tab)
        return NULL;
    put_in_array(str, tab, k);
    tab[k] = NULL;
    return tab;
}
