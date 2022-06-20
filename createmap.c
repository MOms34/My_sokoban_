/*
** EPITECH PROJECT, 2022
** soko
** File description:
** sokoban
*/

#include "../include/my.h"

int nb_obs(char **map, char c)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int z = 0; map[i][z] != '\0'; z++) {
            if (map[i][z] == c)
                count++;
        }
    }
    return (count);
}

int *obs_x(char **map, int nb, char c)
{
    int *obs = NULL;
    int a = 0;

    obs = malloc(sizeof(int) * nb);
    for (int i = 0; map[i] != NULL; i++) {
        for (int z = 0; map[i][z] != '\0'; z++) {
            if (map[i][z] == c) {
                obs[a] = z;
                a++;
            }
        }
    }
    return (obs);
}

int *obs_y(char **map, int nb, char c)
{
    int *obs = NULL;
    int a = 0;

    obs = malloc(sizeof(int) * nb);
    for (int i = 0; map[i] != NULL; i++) {
        for (int z = 0; map[i][z] != '\0'; z++) {
            if (map[i][z] == c) {
                obs[a] = i;
                a++;
            }
        }
    }
    return (obs);
}

void obs(window_t *game)
{
    game->nb_x = nb_obs(game->map_p, 'X');
    game->nb_o = nb_obs(game->map_p, 'O');
    game->nb_p = nb_obs(game->map_p, 'P');
    game->nb_diez = nb_obs(game->map_p, '#');
    game->obs_x_x = obs_x(game->map_p, game->nb_x, 'X');
    game->obs_o_x = obs_x(game->map_p, game->nb_o, 'O');
    game->obs_p_x = obs_x(game->map_p, game->nb_p, 'P');
    game->obs_x_y = obs_y(game->map_p, game->nb_x, 'X');
    game->obs_o_y = obs_y(game->map_p, game->nb_o, 'O');
    game->obs_p_y = obs_y(game->map_p, game->nb_p, 'P');
    game->obs_diez_x = obs_x(game->map_p, game->nb_diez, '#');
    game->obs_diez_y = obs_y(game->map_p, game->nb_diez, '#');
    game->life = TRUE;
    game->temp_nb_o = nb_obs(game->map_p, 'O');
    game->temp_o_x = obs_x(game->map_p, game->nb_o, 'O');
    game->temp_o_y = obs_y(game->map_p, game->nb_o, 'O');
    game->nb_ot = nb_obs(game->map_p, 'O');
}

void construct(char *buffer, window_t *game)
{
    map(buffer, game);
    obs(game);
    game->h = game->max_lent;
    game->w = game->max_word - 1;
}
