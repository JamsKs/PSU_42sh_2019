/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *str, char *dest)
{
    int x;
    int j;
    int i = my_strlen(str) + my_strlen(dest);
    char *src = malloc(sizeof(char) * (i + 1));

    for (x = 0, j = 0; str[x] != '\0'; x++, j++)
        src[j] = str[x];
    for (int y = 0; dest[y] != '\0'; j++, y++)
        src[j] = dest[y];
    return (src);
}