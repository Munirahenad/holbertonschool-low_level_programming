#include "main.h"

/**
 * _sqrt_helper - helper function to find square root using binary search
 * @n: number to find square root of
 * @low: lower bound
 * @high: upper bound
 * Return: natural square root or -1 if not found
 */
int _sqrt_helper(int n, int low, int high)
{
	int mid;
	long square;

	if (low > high)
		return (-1);

	mid = low + (high - low) / 2;
	square = (long)mid * mid;

	if (square == n)
		return (mid);
	else if (square < n)
		return (_sqrt_helper(n, mid + 1, high));
	else
		return (_sqrt_helper(n, low, mid - 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find square root of
 * Return: natural square root or -1 if not found
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	return (_sqrt_helper(n, 1, 46340));
}
