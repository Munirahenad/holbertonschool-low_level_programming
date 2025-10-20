#include "main.h"

/**
 * print_line - draws a straight line using '_' then a newline
 * @n: number of times the character '_' should be printed
 *
 * Return: void
 */
void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
		putchar('');

	_putchar('\n');
}
