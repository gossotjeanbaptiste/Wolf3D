/*
** EPITECH PROJECT, 2025
** Project-Robot_Factory
** File description:
** my_fgets
*/
#include "my.h"

static char *read_buffer
(ssize_t read_len, char *line, int n, char *buffer)
{
    int i = 0;

    if (read_len == -1) {
        free(line);
        return NULL;
    }
    for (i = 0; i < n - 1 && i < read_len; i++) {
        buffer[i] = line[i];
        if (line[i] == '\n') {
            i++;
            break;
        }
    }
    buffer[i] = '\0';
    return buffer;
}

char *my_fgets(char *buffer, int n, FILE *stream)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read_len;

    if (!buffer || n <= 0 || !stream) {
        return NULL;
    }
    read_len = getline(&line, &len, stream);
    if (read_buffer(read_len, line, n, buffer) == NULL) {
        return NULL;
    }
    free(line);
    return buffer;
}
