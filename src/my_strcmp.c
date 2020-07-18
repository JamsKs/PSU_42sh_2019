/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

#include "../include/my.h"

int my_strcmp(const char *str, const char *dest)
{
    int x = 0;

    for (; str[x] == dest[x] &&
    str[x] != '\0' &&
    dest[x] != '\0'; x++) {
    }
    return (str[x] - dest[x]);
}

int my_strncmp(const char *str, const char *dest, int n)
{
    int x = 0;

    for (; str[x] == dest[x] &&
    x != n ; x++) {
    }
    return (str[x] - dest[x]);
}