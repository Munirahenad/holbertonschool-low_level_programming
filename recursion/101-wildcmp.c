#include "main.h"

/**
 * wildcmp - compares two strings, where s2 can contain '*'
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* Base case: both strings ended */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If s2 is '*', try two options */
	if (*s2 == '*')
	{
		/* Option 1: '*' matches zero characters */
		if (wildcmp(s1, s2 + 1))
			return (1);
		/* Option 2: '*' matches at least one character */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
		return (0);
	}

	/* Regular character match */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* Characters don't match */
	return (0);
}
