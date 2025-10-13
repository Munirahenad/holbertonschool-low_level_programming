
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 from 0 to 9,
 * followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char digit;

	for (digit = '0'; digit <= '9'; digit++)
		putchar(digit);

	putchar('\n');

	return (0);
}

