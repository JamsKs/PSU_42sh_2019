/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct minishell
{
    char **path;
    char **flag;
    char *str;
    int x;
    int y;
    int l;
    int len;
} mysh;

int my_putstr(char const *str);
void my_putchar(char c);
int my_strcmp(const char *str, const char *dest);
char **my_str_to_wordarray(char const *str, char delim);
int my_strncmp(const char *str, const char *dest, int n);
int my_strlen(char const *str);
char *stock_path(char **envp);
void print_env(char **envp);
char *my_strcat(char *str, char *dest);
char **my_str_to_wordarray2(char const *str, char delim);
void make_fork(char **envp, char *temp);
char **call_path(char **envp, char **input, mysh *a);
int find_bin(char **envp, char *temp, mysh *a);
int check_env(char *str);
void do_env(char **envp, char *src, mysh *a);
char *prepare_env(char *src);
int count_tab(char **tab);
void my_shell(char **envp, mysh *a);
char *my_strcpy(char *str, char *src);
char *get(char **input);
char **check_flag(char *temp);

#endif
