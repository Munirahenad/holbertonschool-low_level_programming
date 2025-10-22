#include "main.h"

/**
 * print_number - prints an integer using only _putchar
 * @n: integer to print
 */
void print_number(int n)
{
    unsigned int m;

    if (n < 0)
    {
        _putchar('-');
        /* convert to unsigned first, then negate to avoid INT_MIN overflow */
        m = (unsigned int)(- (unsigned int)n);
    }
    else
    {
        m = (unsigned int)n;
    }

    if (m / 10)
        print_number((int)(m / 10));

    _putchar((char)((m % 10) + '0'));
}

