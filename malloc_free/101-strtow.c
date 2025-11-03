#include "main.h"
#include <stdlib.h>

/**
* count_words - counts the number of words in a string
* @str: the string to analyze
*
* Return: number of words
*/
int count_words(char *str)
{
	int i = 0, count = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

/**
* strtow - splits a string into words
* @str: the string to split
*
* Return: pointer to an array of strings (words), or NULL on failure
*/
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, len, wc, start;

	if (str == NULL || *str == '\0')
		return (NULL);

	wc = count_words(str);
	if (wc == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break;
		start = i;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		len = i - start;

		words[k] = malloc(sizeof(char) * (len + 1));
		if (words[k] == NULL)
		{
			while (k > 0)
			{
				k--;
				free(words[k]);
			}
			free(words);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[k][j] = str[start + j];
		words[k][j] = '\0';
		k++;
	}
	words[k] = NULL;

	return (words);
}

