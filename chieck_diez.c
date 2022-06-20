/*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

int check_diez_x(window_t *game, WINDOW *wind, int z)
{
    int p = 0;

    for (int i = 0; i < game->nb_diez + 1; i++) {
        if ((game->obs_p_x[0] + 1) == game->obs_diez_x[i] &&
        game->obs_p_y[0] == game->obs_diez_y[i] && z == 1)
            p += 1;
        if ((game->obs_p_x[0] - 1) == game->obs_diez_x[i] &&
        game->obs_p_y[0] == game->obs_diez_y[i] && z == -1)
            p += 1;
        if (p == 1)
            return (-1);
        p = 0;
    }
    return (0);
}

int check_diez_y(window_t *game, WINDOW *wind, int z)
{
    int p = 0;

    for (int i = 0; i < game->nb_diez + 1; i++) {
        if ((game->obs_p_y[0] + 1) == game->obs_diez_y[i] &&
        game->obs_p_x[0] == game->obs_diez_x[i] && z == 1)
            p += 1;
        if ((game->obs_p_y[0] - 1) == game->obs_diez_y[i] &&
        game->obs_p_x[0] == game->obs_diez_x[i] && z == -1)
            p += 1;
        if (p == 1)
            return (-1);
        p = 0;
    }
    return (0);
}
