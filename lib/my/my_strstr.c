/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** find first occurence of subphrase
*/
#include "my.h"

static int annexe_dos_to_my_strstr
(char const *to_find, char *str, int i, int j)
{
    int found;

    if (str[i + j] != to_find[j])
        found = 0;
    return found;
}

static int annexe_to_my_strstr
(char const *to_find, int size_find, char *str)
{
    int found;
    int size_str = my_strlen(str);

    for (int i = 0; i < (size_str - size_find + 1); i++) {
        found = 1;
        for (int j = 0; j < size_find; j++) {
            annexe_dos_to_my_strstr(to_find, str, i, j);
        }
    }
    return found;
}

char *my_strstr(char *str, char const *to_find)
{
    int size_str = my_strlen(str);
    int size_find = my_strlen(to_find);
    int found;

    if (size_str == 0 || size_find == 0)
        return 0;
    if (size_find > size_str)
        return 0;
    found = annexe_to_my_strstr(to_find, size_find, str);
    if (found == 1) {
        return str;
        }
    return 0;
}
