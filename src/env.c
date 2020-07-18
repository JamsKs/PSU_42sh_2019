/*
** EPITECH PROJECT, 2020
** env.c
** File description:
** env.c
*/

#include "../include/my.h"

int get_path(char **envp)
{
    int x = 0;
    int y = 0;
    char *str = malloc(sizeof(char) * 6);

    for (y = 0; envp[y] != NULL; y++) {
        for (x = 0; x != 5; x++)
            str[x] = envp[y][x];
        if (my_strcmp(str, "PATH=") == 0)
            break;
    }
    return (y);
}

char *stock_path(char **envp)
{
    int y = get_path(envp);
    int z = my_strlen(envp[y]);
    int x;
    int j;
    char *str = malloc(sizeof(char) * (z + 1));

    for (x = 0, j = 5; x != z; x++, j++)
        str[x] = envp[y][j];
    return (str);
}

char **call_path(char **envp, char **input, mysh *a)
{
    char delim = ':';
    char *space = " ";
    char *str = stock_path(envp);
    char **tab = my_str_to_wordarray(str, delim);
    a->path = malloc(sizeof(char) * 30000);
    struct stat ss;

    for (int y = 0; tab[y] != NULL; y++) {
        a->path[0] = my_strcat(tab[y], "/");
        a->path[0] = my_strcat(a->path[0], input[0]);
        if (stat(a->path[0], &ss) != -1) {
            return (a->path);
        }
    }
    return (NULL); 
}

char **check_flag(char *temp)
{
    char **flag = malloc(sizeof(char *) * 1000);
    int line = 0;
    int n = 0;
    int y;

    for (int x = 0; temp[x] != '\0'; x++) {
        if (temp[x] == ' ')
            line++;
    }
    line = line + 1;
    for (y = 0; y != line; y++) {
        flag[y] = malloc(sizeof(char) * 1000);
        for (int x = 0; temp[n] != ' ' && temp[n] != '\n'; n++, x++)
            flag[y][x] = temp[n];
        n++;
    }
    flag[y] = NULL;
    return (flag);
}

int find_bin(char **envp, char *temp, mysh *a)
{
    char **flag = check_flag(temp);
    int i = 0;
    struct stat ss;
    
    stat(flag[0], &ss);
    if (S_ISDIR(ss.st_mode))
        i = 1;
    if (call_path(envp, flag, a) != NULL && i == 0) { 
        pid_t pid = fork();
        if (pid > 0) {
            wait(NULL);
        } else
            execve(a->path[0], flag, envp);
    } else if (i == 1) {
        write(2, flag[0], my_strlen(flag[0]));
        write(2, ": Permission denied.\n", 21);
    } else {
        my_putstr(flag[0]);
        my_putstr(": Command not found.\n");
    }
    if (my_strcmp(flag[0], "env") == 0) {
        if (a->flag[a->l] == NULL && a->l != 0 && a->flag[a->l - 1] != NULL) {
            my_putstr(a->flag[a->l - 1]);
            my_putchar('\n');
        }
    }
}
