#include "main.h"

/**
* puts2 - prints every other character of a string,
* starting with the first character
* @str: input string
*
* Description: This function prints only the characters
* whose index numbers are even (0, 2, 4, ...).
* The odd-indexed characters are skipped using an else statement.
* After finishing, a newline character is printed.
*
* Return: void
*/
void puts2(char *str)
{
int i = 0;

while (str[i] != '\0')
{
if (i % 2 == 0)
{
_putchar(str[i]);
}
else
{

}
i++;
}
_putchar('\n');
}
