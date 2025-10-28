#include "main.h"

/**
 * _strlen_rec - returns the length of a string recursively
 * @s: input string
 *
 * Return: length of string
 */
int _strlen_rec(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_rec(s + 1));
}

/**
 * _check_palindrome - helper to check if s[start..end] is palindrome
 * @s: input string
 * @start: starting index
 * @end: ending index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int _check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (_check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - returns 1 if s is a palindrome, 0 otherwise
 * @s: input string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len;

	if (*s == '\0')
		return (1);
	len = _strlen_rec(s);
	return (_check_palindrome(s, 0, len - 1));
}
