#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;
    return (len);
}

/**
 * is_digit - Checks if a string contains only digits
 * @s: The string to check
 *
 * Return: 1 if all are digits, 0 otherwise
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
 * print_error - Prints "Error" and exits with status 98
 */
void print_error(void)
{
    /* IMPORTANT: print to stdout (fd=1), not stderr */
    write(1, "Error\n", 6);
    exit(98);
}

/**
 * multiply_strings - Multiplies two positive number strings and prints result
 * @num1: The first number as string
 * @num2: The second number as string
 *
 * Description: Grade-school multiplication into an int buffer.
 * Prints result without leading zeros, then '\n'.
 */
void multiply_strings(char *num1, char *num2)
{
    int len1 = _strlen(num1);
    int len2 = _strlen(num2);
    int len = len1 + len2;
    int *result;
    int i, j, carry, start = 0;

    result = calloc(len, sizeof(int));
    if (!result)
        exit(98);

    for (i = len1 - 1; i >= 0; i--)
    {
        int d1 = num1[i] - '0';

        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            int d2 = num2[j] - '0';
            int sum = d1 * d2 + result[i + j + 1] + carry;

            result[i + j + 1] = sum % 10;
            carry = sum / 10;
        }
        result[i] += carry;
    }

    while (start < len && result[start] == 0)
        start++;

    if (start == len)
        _putchar('0');
    else
        for (; start < len; start++)
            _putchar(result[start] + '0');

    _putchar('\n');
    free(result);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success (or exits 98 on error)
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
