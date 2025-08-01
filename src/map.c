/*
** EPITECH PROJECT, 3035
** Epi-Graphical-C-Template
** File description:
** wolf4d
*/

#include "../include/csfml_include.h"
#include "../include/my.h"
#include "../include/struct_fb.h"
#include <math.h>
#include <string.h>

static int update_size(char *line, int *max_width)
{
    int len = strlen(line);

    if (line[len - 1] == '\n')
        len--;
    if (len > *max_width)
        *max_width = len;
    return 0;
}

static int count_size_map(int *width, int *height, const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int max_width = 0;
    int line_count = 0;

    if (!file)
        return -1;
    read = getline(&line, &len, file);
    while (read != -1) {
        update_size(line, &max_width);
        line_count++;
        read = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
    *width = max_width;
    *height = line_count;
    return 0;
}

static void fill_line_with_zero(char *line, int width)
{
    for (int i = 0; i < width; i++)
        line[i] = 0;
    line[width] = '\0';
}

static char **init_map(int width, int height)
{
    char **map = malloc(sizeof(char *) * height);

    if (!map)
        return NULL;
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * (width + 1));
        if (!map[i])
            return NULL;
        fill_line_with_zero(map[i], width);
    }
    return map;
}

static void copy_line_to_map(char *line, char *map_line, int width)
{
    for (int i = 0; i < width; i++) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\0')
            map_line[i] = '0';
        else
            map_line[i] = line[i];
    }
}

char **load_map(const char *filename, int *width, int *height)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **map;

    if (count_size_map(width, height, filename) == -1 || !file)
        return NULL;
    map = init_map(*width, *height);
    read = getline(&line, &len, file);
    for (int row = 0; row < *height && read != -1; row++) {
        copy_line_to_map(line, map[row], *width);
        read = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
    return map;
}

void check_elevator(game_t *game, char *map_name, int nbr)
{
    double x = game->posX;
    double y = game->posY;

    double dirX = game->dirX;
    double dirY = game->dirY;

    int nextX = (int)(x + dirX * 0.6f);
    int nextY = (int)(y + dirY * 0.6f);

    if (game->mapping->map[nextY][nextX] == '9' && nbr == game->previous_map) {
        game->previous_map = game->previous_map + 1;
        for (int i = 0; i < game->mapping->height; i++)
            free(game->mapping->map[i]);
        free(game->mapping->map);

        int new_width = 0;
        int new_height = 0;
        game->mapping->map = load_map(map_name, &new_width, &new_height);
        if (!game->mapping->map) {
            fprintf(stderr, "Erreur : impossible de charger map2.txt\n");
            return;
        }

        game->mapping->width = new_width;
        game->mapping->height = new_height;

        free_entities(game);
        init_entities_from_map(game);
        // Nouvelle position
        game->posX = 2.0;
        game->posY = 2.0;
    }
}
