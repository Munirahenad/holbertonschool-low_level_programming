#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: pointer to the string to convert.
 *
 * Description: The function converts the initial portion of the string
 *              pointed to by s to int. It handles multiple '+' and '-'
 *              signs and stops conversion at first non-digit character.
 *
 * Return: the converted integer. Returns 0 if no numbers found.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0, found_digit = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			if (sign == 1)
				result = result * 10 + (s[i] - '0');
			else
				result = result * 10 - (s[i] - '0');
		}
		else if (found_digit)
			break;
		i++;
	}

	return (result);
}
