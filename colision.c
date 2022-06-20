/*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

int check_x_o(window_t *game)
{
    int x = 0;

    for (int i = 0; i < game->nb_x; i++) {
        for (int j = 0; j < game->nb_o; j++)
            if ((game->obs_x_y[i]) == game->obs_o_y[j] && (game->obs_x_x[i]) == game->obs_o_x[j]) {
                x++;
        }
    }
    if (x == game->nb_o)
        game->nb_ot = 0;
    return (0);
}

int check_os(window_t *game)
{
    int b = 0;

    for (int i = 0; i < game->nb_o; i++) {
        if (game->obs_o_y[i] == game->h - 2 || game->obs_o_y[i] == 1)
            return (1);
        if (game->obs_o_x[i] == game->w - 2 || game->obs_o_x[i] == 1)
            return (2);
    }
    return (0);
}

int check_xos(window_t *game, int i)
{
    if (game->obs_x_x[i] == 1 || game->obs_x_x[i] == game->w - 2 ) {
        if (game->obs_x_y[i] >= 1 || game->obs_x_y[i] <= game->h - 1)
            return (1);
        }
    if (game->obs_x_x[i] > 1 && game->obs_x_x[i] < game->w - 1 ) {
        if (game->obs_x_y[i] == 1 || game->obs_x_y[i] == game->h - 2)
            return (2);
        }
    return 0;
}

void check_ces(window_t *game)
{
    for (int i = 0; i < game->nb_x; i++) {
        if (check_xos(game, i) == 2 && check_os(game) != 1)
            game->endc += 1;
        if (check_xos(game, i) == 1 && check_os(game) != 2)
            game->endc += 1;
        if (check_xos(game, i) == 1 && check_os(game) == 1 && game->nb_x == 1) {
            game->endc = 1;
            return;
        }
        }
        if (game->endc != 2)
            game->endc = 0;
}
