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
char *se, *so, **vi = NULL;
int ws;
struct stat ft;
size_t n = 0;
ssize_t nred;
se = NULL;
/*while (env[i] != NULL)
{
if (strcmpr(env[i], "SHLVL=1") == 0)
{
write(1, "$ ", 2);
status = 1;
}
i++;
}*/
while ((nred = getline(&se, &n, stdin)) != -1)
{
vi = tokenizer(se);
vi[0] = _command(env, vi[0], vi);
so = vi[0];
if (strcmpr(so, "exit") == 0)
return (0);
if (stat(so, &ft) != 0 && strcmpr(so, "setenv") != 0 && strcmpr(so, "unsetenv") != 0)
error_printer(vs[0], so);
if (stat(so, &ft) == 0)
{
if (fork() == 0)
{
if (execve(vi[0], vi, env) == -1)
{
perror("Error");
}
}
else
{
if (wait(&ws) != -1)
fflush(stdout);
}
}
}
free(se);
free(vi);
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
if (strcmpr(var, variable) == 0)
{
break;
}
i++;
}
return (i);
}
