#ifndef _MAIN_H
#define _MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
/**
 * struct path_s - struct for the path linked list
 * @path: the path value
 * @next: the pointer to the next path
 * Description: singly linked list node structure
*/
typedef struct path_s
{
char *path;
void *next;
} path_t;
char *strtok_test(char *str, char *delim);
int strcmpr(char *a, char *b);
void _unsetenv(char **environ, char *var);
void _setenv(char **environ, char *var, char *value);
char *_command(char **env, char *so, char **vi);
#endif
