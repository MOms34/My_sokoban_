/*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    wrefresh(local_win);

    return local_win;
}

int posp(window_t *game, int i)
{
        if (game->obs_p_x[0] == game->obs_o_x[i]) {
            if (game->obs_p_y[0] == game->obs_o_y[i])
                return (1);
        }
    return (0);
}

void render(window_t *game, WINDOW *wind)
{
    werase(wind);
    for (int i = 0; i < game->nb_diez + 1; i++) {
        mvwprintw(wind, game->obs_diez_y[i], game->obs_diez_x[i], "#");
    }
    mvwprintw(wind, game->obs_p_y[0], game->obs_p_x[0], "P");
    for (int i = 0; i < game->nb_ot; i++) {
        if (posp(game, i) == 0)
            mvwprintw(wind, game->obs_o_y[i], game->obs_o_x[i], "O");
    }
    for (int i = 0; i < game->nb_x; i++) {
        mvwprintw(wind, game->obs_x_y[i], game->obs_x_x[i], "X");
    }
    wrefresh(wind);

}
