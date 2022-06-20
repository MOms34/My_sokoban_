/*
** EPITECH PROJECT, 2022
** Sokoban
** File description:
** Semestre 2
*/

#include "../include/my.h"

void run(window_t *game, WINDOW *wind)
{
    while (game->life) {
        update_ps(game, wind);
        if (mvwprintw(wind, game->obs_p_y[0], game->obs_p_x[0], "P") < 0)
            game->life = false;
        render(game, wind);
        if (check_x_o(game) == 1) {
        }
        check_ces(game);
        if (game->nb_ot == 0)
            game->life = false;
        if (game->endc == game->nb_x) {
            game->life = false;
        }
        usleep(100000);
    }
}

void init(window_t *game)
{
    WINDOW *wind = NULL;
    initscr();
    curs_set(false);
    refresh();
    wind = create_newwin(game->h, game->w,
    (LINES - game->h) / 2, (COLS - game->w) / 2);
    keypad(wind, true);
    nodelay(wind, TRUE);
    endwin();
    run(game, wind);
}

void errors_flags(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, ");
    my_putstr("containing '#' for walls, \n");
    my_putstr("\t'P' for the player, 'X' for boxes and");
    my_putstr(" 'O' for storage locations.\n");
}

int main(int argc, char **argv)
{
    char *filepath = argv[1];
    window_t *game = malloc(sizeof(window_t));
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);

    if (argc != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2) {
        errors_flags();
        return 0;
    }
    if (fd < 0)
        return (84);
    buffer = my_buffer(filepath, game);
    if (check_buffer(buffer) == -1)
        return (84);
    construct(buffer, game);
    if (my_buffer_false(game) == -1)
        return 84;
    init(game);
    if (game->endc == game->nb_x) {
            game->life = false;
            return 1;
    }
    return 0;
}
