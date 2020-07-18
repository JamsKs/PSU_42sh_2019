/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../include/my.h"

void print_env(char **envp)
{
    for (int x = 0; envp[x] != NULL; x++) {
        my_putstr(envp[x]);
        my_putchar('\n');
    }
}

void make_cd(char *temp)
{
    int i = my_strlen(temp);
    int n = 0;
    char *dest = malloc(sizeof(char) * (i + 1));

    for (int x = 3; temp[x] != '\n'; x++, n++)
        dest[n] = temp[x];
    chdir(dest);
}

char *space_handling(char *temp)
{
    int i = my_strlen(temp);
    int y = 0;
    int x = 0;
    char *dest = malloc(sizeof(char) * (i + 1));
    char *src = malloc(sizeof(char) * (i + 1));
 for ( ; dest[x] != '\0'; x++, y++) {
        for ( ;dest[x] == ' ' && dest[x + 1] == ' '; x++) {
        }
        if (y == 0 && dest[x] == ' ')
          x = x + 1;
        src[y] = dest[x];
    }

    for (int n = 0, m = 0; temp[n] != '\0'; n++, m++) {
        for ( ; temp[n] == '\t'; n++) {
        }
        dest[m] = temp[n];
    }
    for ( ; dest[x] != '\0'; x++, y++) {
        for ( ;dest[x] == ' ' && dest[x + 1] == ' '; x++) {
        }
        if (y == 0 && dest[x] == ' ')
          x = x + 1;
        src[y] = dest[x];
    }
    return (src);
}

void my_shell(char **envp, mysh *a)
{
    size_t size = 0;
    char *temp = NULL;
    char *str;
    char *src;

    while (1) {
        my_putstr("$>");
        if (getline(&temp, &size, stdin) == -1) {
            my_putstr(" exit\n");
            break;
        }
        src = space_handling(temp);
        str = malloc(sizeof(char) * (my_strlen(src) + 1));
        for (int x = 0, y = 0; x < 2; x++, y++)
            str[y] = temp[x];
        if (my_strcmp(temp, "exit\n") == 0) {
            my_putstr("exit\n");
            exit (0);
        }
        if (my_strcmp(str, "cd") == 0)
            make_cd(temp);
        else if (check_env(src) == 1)
            do_env(envp, src, a);
        else
            find_bin(envp, src, a);
    }
}

void do_str(mysh *a)
{
    a->str = NULL;
    a->l = 0;
    a->flag = malloc(sizeof(char *) *100);
}

int main(int ac, char **av, char **envp)
{
    mysh a;

    if (ac == 1) {
        do_str(&a);
        my_shell(envp, &a);
    }
    else
        return (84);
    return (0);
}
