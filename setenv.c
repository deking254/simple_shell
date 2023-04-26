#include "main.h"
/**
 * _setenv - check the code
 * @environ: environment
 * @var: name of the variable to set
 * @value: the value the var points to
 * Return: nothing
 */
void _setenv(char **environ, char *var, char *value)
{
char *tmp;
char temp[100];
int j, k, l, m, i = 0;
char *variablecat = NULL;
while (environ[i] != NULL)
{
tmp = environ[i];
k = 0;
while (tmp[k] != '=')
{
k++;
}
j = 0;
while (j < k)
{
temp[j] = tmp[j];
j++;
}
temp[j] = '\0';
if (strcmpr(temp, var) == 0)
{
l = 0;
while (var[l] != '\0')
l++;
var[l] = '=';
variablecat = malloc(l + 1);
if (variablecat != NULL)
{
m = 0;
while (m <= l)
{
variablecat[m] = var[m];
m++; }
variablecat[m] = '\0';
environ[i] = strcatr(value, variablecat);
}
break;
}
i++;
}
}
