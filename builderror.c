/*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

int my_buffer_false(window_t *game)
{
    if (game->nb_o != game->nb_x || game->nb_o == 0)
        return (-1);
    if (game->nb_p != 1 || game->nb_diez == 0)
        return (-1);
    return (0);
}

int check_buffer(char *buffer)
{
    int z = 0;
    char *str = " XOP#\n";

    for (int i = 0; buffer[i] != '\0'; i++) {
        for (int j = 0; str[j] != '\0'; j++) {
            if (buffer[i] == str[j])
                break;
            if (j == 5 && str[j] != buffer[i])
                return (-1);
        }
    }
    return (0);
}
