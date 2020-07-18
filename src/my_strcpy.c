/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** my_strcpy
*/

#include "../include/my.h"

char *my_strcpy(char *str, char *src)
{
    int x = 0;
    int i = my_strlen(src);

    if (str == NULL) {
        str = malloc(sizeof(char) * (i + 1));
        if (str == NULL)
            return (NULL);
    }
    while (src[x] != '\0') {
        str[x] = src[x];
        x++;
    }
    str[x] = '\0';
    return (str);
}
