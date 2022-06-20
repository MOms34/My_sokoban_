/*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

int check_l_obs(window_t *game, int i)
{
    int z = i;

    for (int i = 0; i < game->nb_diez + 1; i++) {
        if ((game->obs_x_y[z] + 1) == game->obs_diez_y[i]) {
            if ((game->obs_x_x[z]) == game->obs_diez_x[i])
                return (1);
        }
        if ((game->obs_x_y[z] - 1) == game->obs_diez_y[i]) {
            if ((game->obs_x_x[z]) == game->obs_diez_x[i])
                return (1);
        }
    }
    return (0);
}

int check_l_obs_y(window_t *game, int i)
{
    int z = i;

    for (int i = 0; i < game->nb_diez + 1; i++) {
        if ((game->obs_x_x[z] + 1) == game->obs_diez_x[i]) {
            if ((game->obs_x_y[z]) == game->obs_diez_y[i])
                return (1);
        }
        if ((game->obs_x_x[z] - 1) == game->obs_diez_x[i]) {
            if ((game->obs_x_y[z]) == game->obs_diez_y[i])
                return (1);
        }
    }
    return (0);
}

int check_l_x(window_t *game, int i)
{
    int z = i;

    for (int i = 0; i < game->nb_x; i++) {
        if (i == z)
            i++;
        if ((game->obs_x_y[z] + 1) == game->obs_x_y[i]) {
            if ((game->obs_x_x[z]) == game->obs_x_x[i])
                return (1);
        }
        if ((game->obs_x_y[z] - 1) == game->obs_x_y[i]) {
            if ((game->obs_x_x[z]) == game->obs_x_x[i])
                return (1);
        }
    }
    return (0);
}

int check_l_y(window_t *game, int i)
{
    int z = i;

    for (int i = 0; i < game->nb_x; i++) {
        if (i == z)
            i++;
        if ((game->obs_x_x[z] + 1) == game->obs_x_x[i]) {
            if ((game->obs_x_y[z]) == game->obs_x_y[i])
                return (1);
        }
        if ((game->obs_x_x[z] - 1) == game->obs_x_x[i]) {
            if ((game->obs_x_y[z]) == game->obs_x_y[i])
                return (1);
        }
    }
    return (0);
}
