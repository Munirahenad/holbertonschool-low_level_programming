#include <stdio.h>

void print_before_main(void) __attribute__((constructor));

/**
 * print_before_main - prints a message before main is executed
 *
 * This function is executed automatically before main
 * because of the constructor attribute.
 */
void print_before_main(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}

