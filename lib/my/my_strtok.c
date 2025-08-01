/*
** EPITECH PROJECT, 2025
** Project-my_radar
** File description:
** my_strtok
*/
#include "my.h"

// Fonction pour vérifier si un caractère est un délimiteur
static int is_delimiter(char c, const char *delim)
{
    for (int i = 0; delim[i] != '\0'; ++i) {
        if (c == delim[i]) {
            return 1;
        }
    }
    return 0;
}

// Fonction pour trouver la fin d'un token
static char *find_token_end(char *str, const char *delim)
{
    while (*str != '\0' && is_delimiter(*str, delim)) {
        str++;
    }
    while (*str != '\0' && !is_delimiter(*str, delim)) {
        str++;
    }
    return str;
}

char *my_strtok(char *str, const char *delim)
{
    static char *next;
    char *token;

    if (str != NULL) {
        next = str;
    }
    if (next == NULL || *next == '\0') {
        return NULL;
    }
    token = next;
    next = find_token_end(next, delim);
    *next = '\0';
    next++;
    return token;
}
