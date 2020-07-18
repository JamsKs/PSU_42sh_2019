/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** 03/10/19 10:41
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
