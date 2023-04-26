#include "main.h"
/**
 * error_printer - prints the errors
 * @name: name of the program
 * @command: command entered
 * Return: Always 0.
 */
void error_printer(char *name, char *command)
{
int i = 0, j = 0;
while (name[i] != '\0')
i++;
while (command[j] != '\0')
j++;
write(1, name, i);
write(1, ": 1: ", 5);
write(1, command, j);
write(1, ": not found\n", 12);
}
