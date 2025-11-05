#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static void print_error_and_exit(void)
{
    printf("Error\n");
    exit(98);
}

static int is_digits_only(const char *s)
{
    if (!s || *s == '\0')
        return 0;
    while (*s)
    {
        if (!isdigit((unsigned char)*s))
            return 0;
        s++;
    }
    return 1;
}

static int _strlen(const char *s)
{
    int len = 0;
    while (s && s[len])
        len++;
    return len;
}

int main(int argc, char *argv[])
{
    char *s1, *s2;
    int len1, len2, total_len, i, j;
    int *res;
    int carry, n1, n2;
    int start;

    if (argc != 3)
        print_error_and_exit();

    s1 = argv[1];
    s2 = argv[2];

    if (!is_digits_only(s1) || !is_digits_only(s2))
        print_error_and_exit();

    len1 = _strlen(s1);
    len2 = _strlen(s2);
    total_len = len1 + len2;

    res = (int *)calloc(total_len, sizeof(int));
    if (!res)
        print_error_and_exit();

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = s1[i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = s2[j] - '0';
            int sum = res[i + j + 1] + n1 * n2 + carry;

            res[i + j + 1] = sum % 10;
            carry = sum / 10;
        }
        res[i] += carry;
    }

    start = 0;
    while (start < total_len - 1 && res[start] == 0)
        start++;

    for (i = start; i < total_len; i++)
        putchar(res[i] + '0');
    putchar('\n');

    free(res);
    return 0;
}


























































































