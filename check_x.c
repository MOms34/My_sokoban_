/*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

int check_xx(window_t *game, int z)
{
    for (int i = 0; i < game->nb_x; i++) {
        if ((game->obs_p_x[0] + 1) == game->obs_x_x[i] &&
        game->obs_p_y[0] == game->obs_x_y[i] && z == 1) {
            if (check_l_obs_y(game, i) == 1 || check_l_y(game, i) == 1)
                return -1;
            game->obs_x_x[i] += 1;
        }
        if ((game->obs_p_x[0] - 1) == game->obs_x_x[i] &&
        game->obs_p_y[0] == game->obs_x_y[i] && z == -1) {
            if (check_l_obs_y(game, i) == 1 || check_l_y(game, i) == 1)
                return -1;
            game->obs_x_x[i] -= 1;
        }
    }
    return 0;
}

int check_x_y(window_t *game, int z)
{
    for (int i = 0; i < game->nb_x; i++) {
        if ((game->obs_p_y[0] + 1) == game->obs_x_y[i] &&
        game->obs_p_x[0] == game->obs_x_x[i] && z == 1){
            if (check_l_obs(game, i) == 1 || check_l_x(game, i) == 1)
                return -1;
            game->obs_x_y[i] += 1;
        }
        if ((game->obs_p_y[0] - 1) == game->obs_x_y[i] &&
        game->obs_p_x[0] == game->obs_x_x[i] && z == -1) {
            if (check_l_obs(game, i) == 1 || check_l_x(game, i) == 1)
                return -1;
            game->obs_x_y[i] -= 1;
        }
    }
    return 0;
}
