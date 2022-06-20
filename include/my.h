/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** File Header
*/

#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <ncurses.h>
#include <time.h>

#ifndef MY_H
    #define MY_H

typedef struct window_s {
    char *buffer;
    int max_word;
    int max_lent;
    char **map_p;
    char **map_v;
    int nb_x;
    int nb_p;
    int nb_o;
    int nb_diez;
    int *obs_x_x;
    int *obs_p_x;
    int *obs_o_x;
    int *obs_x_y;
    int *obs_p_y;
    int *obs_o_y;
    int nb_ot;
    int *obs_diez_x;
    int *obs_diez_y;
    int h;
    int w;
    int clean;
    int temp_nb_o;
    int *temp_o_y;
    int *temp_o_x;
    bool life;
    int error;
    int er;
    int er1;
    int os;
    int endc;
    WINDOW *wind;
} window_t;

typedef struct s_node {
    void *elem;
    struct s_node *next;
}t_node;

void my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int number_fd(char *filepath, window_t *game);
char *my_buffer(char *filepath, window_t *game);
char **creat_map(window_t *game);
char **map_1(char *buffer, window_t *game);
void map(char *buffer, window_t *game);
int nb_obs(char **map, char c);
int *obs_x(char **map, int nb, char c);
int *obs_y(char **map, int nb, char c);
void obs(window_t *game);
void construct(char *buffer, window_t *game);
int my_buffer_false(window_t *game);
int check_buffer(char *buffer);
WINDOW *create_newwin(int height, int width, int starty, int startx);
int posp(window_t *game, int i);
void render(window_t *game, WINDOW *wind);
int check_diez_x(window_t *game, WINDOW *wind, int z);
int check_diez_y(window_t *game, WINDOW *wind, int z);
int check_l_obs(window_t *game, int i);
int check_l_obs_y(window_t *game, int i);
int check_l_x(window_t *game, int i);
int check_l_y(window_t *game, int i);
int check_xx(window_t *game, int z);
int check_x_y(window_t *game, int z);
void update_ps(window_t *game, WINDOW *wind);
int check_x_o(window_t *game);
int check_os(window_t *game);
int check_xos(window_t *game, int i);
void check_ces(window_t *game);

#endif
