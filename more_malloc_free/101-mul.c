#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _strlen - compute length of string
 * @s: input string
 *
 * Return: length as int
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * is_digit - check that a string is composed only of digits 0..9
 * @s: input string
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	if (!s || s[0] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_error - print "Error" and exit with status 98
 *
 * Return: never returns
 */
void print_error(void)
{
	/* write to stderr per project convention */
	write(2, "Error\n", 6);
	exit(98);
}

/**
 * multiply_strings - multiply two positive integer strings and print result
 * @num1: first positive integer as string
 * @num2: second positive integer as string
 *
 * Description: classic grade-school multiplication stored into an int buffer.
 * Prints the result with no leading zeros (unless result is zero), then '\n'.
 * Exits with 98 on allocation failure.
 */
void multiply_strings(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int out_len = len1 + len2;
	int *out;
	int i, j, carry, start = 0;

	out = calloc(out_len, sizeof(int));
	if (!out)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		int d1 = num1[i] - '0';

		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			int d2 = num2[j] - '0';
			int idx = i + j + 1;
			int sum = d1 * d2 + out[idx] + carry;

			out[idx] = sum % 10;
			carry = sum / 10;
		}
		out[i] += carry;
	}

	while (start < out_len && out[start] == 0)
		start++;

	if (start == out_len)
		_putchar('0');
	else
	{
		for (; start < out_len; start++)
			_putchar(out[start] + '0');
	}
	_putchar('\n');
	free(out);
}

/**
 * main - entry point: validate args then multiply
 * @argc: args count
 * @argv: args vector
 *
 * Return: 0 on success, 98 on error (via print_error)
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	multiply_strings(argv[1], argv[2]);
	return (0);
}

