#include "main.h"

/**
 *print_line- print line segun el paremtro pasado
 *
 *@n: parametro a evaluar
 *
 *Return: numero de lineas pasado
 */
void print_line(int n)
{
	for (; n > 0; n--)
		_putchar('_');
	_putchar('\n');
}
