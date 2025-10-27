#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: double pointer to the string pointer to modify
 * @to: pointer to the string to set
 *
 * Return: void
 */
void set_string(char **s, char *to)
{
	char **temp = s;
	*temp = to;
}
