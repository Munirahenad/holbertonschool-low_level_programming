#include "main.h"

/**
 * is_divisible - helper function to check if n is divisible by any number
 * @n: number to check
 * @divisor: current divisor to test
 * Return: 1 if prime, 0 if not prime
 */
int is_divisible(int n, int divisor)
{
	if (n < 2)
		return (0);
	if (divisor * divisor > n)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (is_divisible(n, divisor + 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * @n: number to check
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (is_divisible(n, 2));
}
