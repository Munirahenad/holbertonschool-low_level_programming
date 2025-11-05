#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_digit(char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

int _strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

void errors(void)
{
    printf("Error\n");
    exit(98);
}

void multiply(char *num1, char *num2)
{
    int len1 = _strlen(num1), len2 = _strlen(num2), len = len1 + len2;
    int *result = calloc(len, sizeof(int));
    int i, j, n1, n2, sum, start = 0;

    if (!result)
        exit(98);

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    while (start < len && result[start] == 0)
        start++;
    if (start == len)
        _putchar('0');
    for (; start < len; start++)
        _putchar(result[start] + '0');
    _putchar('\n');
    free(result);
}

int main(int argc, char *argv[])
{
    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        errors();
    multiply(argv[1], argv[2]);
    return (0);
}

