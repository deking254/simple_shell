/**
 * strcatr - concatenates two strings
 * @a: second
 * @a: first
 * Return: buffer
 */
char *strcatr(char *a, char *b)
{
char *final = b;
while (*b)
b++;
while (*a)
*b++ = *a++;
*b = *a;
return (final);
}
