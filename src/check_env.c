/*
** EPITECH PROJECT, 2020
** check env
** File description:
** check env
*/

#include "../include/my.h"

int check_env(char *str)
{
    char *src = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; str[i] != ' ' && str[i] != '\n'; i++)
        src[i] = str[i];
    if (my_strcmp(src, "setenv") == 0)
        return (1);
    if (my_strcmp(src, "unsetenv") == 0)
        return (1);
    return (0);
}

char *prepare_env(char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (int i = 0; src[i] != ' ' && src[i] != '\n'; i++)
        str[i] = src[i];
    return (str);
}

int count_tab(char **tab)
{
    int i = 0;
    
    for (; tab[i] != NULL; i++);
    return (i);
}

char *get(char **input)
{
    char *str;

    if (input[1] == NULL)
        return (NULL);
    else
        str = my_strcat(input[1], "=");
    if (input[2] != NULL)
        str = my_strcat(str, input[2]);
    return (str);
}

void my_setenv(char **input, char **envp, mysh *a)
{
    a->str = get(input);
    a->flag[a->l] = malloc(sizeof(char) * 100);
    a->flag[a->l] = a->str;
    if (input[1] == NULL) {
        print_env(envp);
        if (a->flag[a->l] == NULL && a->l != 0) {
            my_putstr(a->flag[a->l - 1]);
            my_putchar('\n');
        }
    }
    a->l++;
}

void do_env(char **envp, char *src, mysh *a)
{
    char *str = prepare_env(src);
    char **input = check_flag(src);
    int i = count_tab(input);

    if (my_strcmp(input[0], "setenv") == 0) {
        if (i > 3) {
            my_putstr("setenv: Too many arguments.\n");
            return;
        } else {
            if (i == 2) {
                for (int x = 1; x != 2; x++) {
                    for (int y = 0; input[x][y] != '\0'; y++)
                        if (input[x][y] == '=') {
                            my_putstr("setenv: Variable name must contain alphanumeric characters. \n");
                            return;
                        }
                }
            }
            my_setenv(input, envp, a);
        }
    }
    if (my_strcmp(input[0], "unsetenv") == 0) {
        if (input[1] == NULL)
            my_putstr("unsetenv: Too few arguments.\n");
        else
            a->l++;
    }
}
