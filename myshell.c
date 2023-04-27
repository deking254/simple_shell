#include "main.h"
char **tokenizer(char *str);
void printenv(char *environment[]);
int getenvid(char *variable, char **env);
/**
 * main - PID
 *@a: int
 *@vs: char list
 *@env: environment
 * Return: Always 0.
 */
int main(__attribute__((unused))int a, char *vs[], char *env[])
{
char **vi;
char *se;
int ws, i = 0;
struct stat ft;
size_t n = 0;
ssize_t nred = 0;
se = NULL;
while (nred != -1)
{
nred = getline(&se, &n, stdin);
vi = tokenizer(se);
vi[0] = _command(env, vi[0], vi);
while (vi[i] != NULL)
i++;
if (i > 1)
vi[0] = "rtrt";
if (stat(vi[0], &ft) != 0)
{
perror(vs[0]);
}
if (stat(vi[0], &ft) == 0)
{
if (fork() == 0)
{
if (execve(vi[0], vi, env) == -1)
{
perror("Error: ");
}
}
else
{
wait(&ws);
}
}
}
free(se);
return (0);
}
/**
 *tokenizer - function
 *@str: values entered into shell
 * Return: Always character pointer.
*/
char **tokenizer(char *str)
{
char *so;
int t = 0, i = 0, j = 0, w = 0;
char **tokenarr;
while (str[i] != '\0')
{
if (str[i] == 32)
{
w++;
}
i++;
}
if (w == 0)
{
tokenarr = malloc(sizeof(char *) * 2);
while (str[t] != '\0')
{
if (str[t] < 32)
str[t] = '\0';
t++;
}
tokenarr[0] = str;
tokenarr[1] = NULL;
}
if (w > 0)
{
tokenarr = malloc(sizeof(char *) * (w + 2));
so = strtok(str, " ");
tokenarr[j] = so;
w--;
j++;
while (w > 0)
{
tokenarr[j] = strtok(NULL, " ");
j++;
w--;
}
if (w == 0)
{
tokenarr[j] = strtok(NULL, "\n");
j++;
}
tokenarr[j] = NULL;
}
return (tokenarr);
}
/**
 *getenvid - function
 *@variable: var
 *@environ: environment
 * Return: Always position of variable in environ.
*/
int getenvid(char *variable, char **environ)
{
char *var;
int j, i = 0;
while (environ[i])
{
var = environ[i];
j = 0;
while (var[j] != '=')
j++;
var[j] = '\0';
if (strcmp(var, variable) == 0)
{
break;
}
i++;
}
return (i);
}
