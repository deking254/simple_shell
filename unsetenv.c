#include "main.h"
/**
 * _unsetenv - check the code
 * @environ: env
 * @variable: name of variable to delete
 * Return: Always 0.
 */
void _unsetenv(char **environ, char *variable)
{
char **env_tmp;
char *temp;
char tmp[100];
int r, k, i = 0, l = 0, m = 0, n = 0, p = 0;
while (environ[l] != NULL)
l++;
env_tmp = malloc(sizeof(char *) * (l + 1));
while (environ[i] != NULL)
{
temp = environ[i];
k = 0;
while (temp[k] != '=')
{
k++;
}
r = 0;
while (r < k)
{
tmp[r] = temp[r];
r++;
}
tmp[r] = '\0';
if (strcmpr(tmp, variable) == 0)
{
i++;
}
env_tmp[m] = environ[i];
i++;
m++; }
env_tmp[m + 1] = NULL;
while (environ[n] != NULL)
{
environ[n] = NULL;
n++; }
while (env_tmp[p] != NULL)
{
environ[p] = env_tmp[p];
p++; }
}
