/**
 * strcmpr - check code.
 * @a: first
 * @b: dest
 *
 * Return: int
 */
int strcmpr(char *a, char *b)
{
while (*a && *b)
{
if (*a != *b)
return (*a - *b);
a++;
b++;
}
if (*a == *b)
return (0);
else
if (*a < *b)
return (-1);
else
return (1);
}
