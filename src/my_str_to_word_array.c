/*
** EPITECH PROJECT, 2020
** str to word array
** File description:
** str to word array
*/

#include "../include/my.h"

int count_line(char const *str, char delim)
{
    int line = 0;

    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == delim)
            line++;
    }
    return (line);
}

int count_char_line(char const *str, char delim, int x)
{
    int col = 0;
    
    for (; str[x] != delim; x++)
        col++;
    return (col);
}

char **my_str_to_wordarray(char const *str, char delim)
{
    int line = count_line(str, delim);
    char **tab = malloc(sizeof(char *) * (line + 2));
    int b = 0;
    int x = 0;
    int y = 0;
    int col;

    for (y = 0; y != line; y++) {
        col = count_char_line(str, delim, b);
        tab[y] = malloc(sizeof(char) * (col + 1));
        for (x = 0; x < col; x++, b++) {
            tab[y][x] = str[b];
        }
        b++;
        tab[y][x] = '\0';
    }
    tab[y] = NULL;
    return (tab);
}

char **my_str_to_wordarray2(char const *str, char delim)
{
    int line = count_line(str, delim) + 1;
    char **tab = malloc(sizeof(char *) * (line + 2));
    int b = 0;
    int x = 0;
    int y = 0;

    for (y = 0; y != line; y++) {
        tab[y] = malloc(sizeof(char) * (my_strlen(str) + 1));
        for ( ; str[b] != '\n' && str[b] != ' '; b++) {
                tab[y][x] = str[b];
                x++;
        }
    }
    tab[y] = NULL;
    return (tab);
}
