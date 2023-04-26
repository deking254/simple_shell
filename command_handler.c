#include "main.h"
/**
 * _command - check the code
 * @env: envrionment
 * @so: first word entered
 * @vi: a pointer of words entered
 * Return: modified first word
 */
char *_command(char **env, char *so, char **vi)
{
char buf[20];
char pwd[] = {'P', 'W', 'D', '\0'};
if (strcmpr(so, "unsetenv") == 0)
_unsetenv(env, vi[1]);
if (strcmpr(so, "setenv") == 0)
_setenv(env, vi[1], vi[2]);
if (strcmpr(so, "exit") == 0)
{
if (vi[1])
exit(atoi(vi[1]));
else
exit(EXIT_SUCCESS);
}
if (strcmpr(so, "env") == 0)
so  = "/bin/printenv";
if (strcmpr(so, "cd") == 0)
{

_setenv(env, pwd, vi[1]);
chdir(vi[1]);
printf("%s\n", getcwd(buf, 25));
}
if (strcmpr(so, "ls") == 0)
so = "/bin/ls";
return (so);
}
