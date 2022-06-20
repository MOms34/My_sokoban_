/*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

void update_ps(window_t *game, WINDOW *wind)
{
    int c = wgetch(wind);
    if (c) {
        if (c == KEY_DOWN && check_diez_y(game, wind, 1) == 0
        && check_x_y(game, 1) == 0 )
            game->obs_p_y[0] += 1;
        else if (c == KEY_UP && check_diez_y(game, wind, -1) == 0
        && check_x_y(game, -1) == 0)
            game->obs_p_y[0] -= 1;

        else if (c == KEY_LEFT && check_diez_x(game, wind, -1) == 0
        && check_xx(game, -1) == 0 )
            game->obs_p_x[0] -= 1;
        else if (c == KEY_RIGHT && check_diez_x(game, wind, 1) == 0
        && check_xx(game, 1) == 0 )
            game->obs_p_x[0] += 1;
    }
}
