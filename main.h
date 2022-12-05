#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
extern char **environ;
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _str_n_cmp(char *s1, char *s2, int n);
int command_read(char *s, int __attribute__((unused)) characters);
int execute(char *cmd_arr[]);
int _printenv(void);
char *_getenv(char *name);
char *command_path(char *cmd);
#endif
