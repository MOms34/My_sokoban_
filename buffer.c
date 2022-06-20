    /*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

int number_fd(char *filepath, window_t *game)
{
    int fd = open(filepath, O_RDONLY);
    int count = 0;
    char c = '\0';
    int z = 0;
    int count2 = 0;

    while (read (fd, &c, 1)) {
        if ((c == '\n') && z > game->max_word) {
            game->max_word = z;
            z = 0;
        }
        if (c == '\0' || c == '\n') {
            z = 0;
            count2 += 1;
        }
        count++;
        z++;
    }
    game->max_lent = count2;

    return count;
}

char *my_buffer(char *filepath, window_t *game)
{
    int count = number_fd(filepath, game);
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);
    char c = '\0';
    int i = 0;

    buffer = malloc(sizeof(char) * count + 1);
    while (read(fd, &c, 1)) {
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    game->buffer = buffer;
    return buffer;
}

char **creat_map(window_t *game)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * game->max_lent);

    for (int z = 0; z < game->max_lent; z++)
        map[z] = malloc(sizeof(char) * game->max_word);
    map[game->max_lent] = NULL;
    return map;
}

char **map_1(char *buffer, window_t *game)
{
    char **map = creat_map(game);
    int i = 0;
    int z = 0;
    int y = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            map[z][y] = '\0';
            z += 1;
            y = 0;
            i++;
        }
        if (buffer[i] == '\0')
            break;
        map[z][y] = buffer[i];
        i++;
        y++;
    }
    return map;
}

void map(char *buffer, window_t *game)
{
    char **map_p = map_1(buffer, game);
    game->map_p = map_1(buffer, game);

    for (int i = 0; map_p[i] != NULL; i++) {
        for (int z = 0; map_p[i][z] != '\0'; z++) {
            if (map_p[i][z] == 'P' || map_p[i][z] == 'X' || map_p[i][z] == 'O')
                map_p[i][z] = ' ';
        }
    }
    for (int i = 0; map_p[i] != NULL; i++)
    game->map_v = game->map_p;

}
