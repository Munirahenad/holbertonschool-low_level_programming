#include "main.h"
#include <stdlib.h>

/**
* strtow - splits a string into words (space-separated)
* @str: input string
*
* Return: pointer to array of words, or NULL on failure/empty
*/
char **strtow(char *str);

/**
* word_count - count words in a string separated by spaces
* @str: input string
*
* Return: number of words found
*/
static int word_count(char *str);

/**
* word_len - compute the length of the next word starting at index start
* @str: input string
* @start: starting index of the word
*
* Return: length in characters of the word
*/
static int word_len(char *str, int start);

/**
* dup_word - allocate and copy a word substring
* @str: source string
* @start: starting index of the word in @str
* @len: length of the word to copy
*
* Return: pointer to newly allocated null-terminated word, or NULL on failure
*/
static char *dup_word(char *str, int start, int len);

/**
* free_words - free an array of words up to a given index
* @words: array of strings to free
* @upto: number of valid entries to free (from 0 to upto - 1)
*
* Return: Nothing.
*/
static void free_words(char **words, int upto);

/**
* strtow - splits a string into words (space-separated)
* @str: input string
*
* Return: pointer to array of words, or NULL on failure/empty
*/
char **strtow(char *str)
{
	char **words;
	int i, k = 0, pos = 0, wc, len;

	if (str == NULL || *str == '\0')
		return (NULL);

	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = (char **)malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i < wc; i++)
	{
		while (str[pos] == ' ')
			pos++;
		len = word_len(str, pos);
		words[k] = dup_word(str, pos, len);
		if (words[k] == NULL)
		{
			free_words(words, k);
			return (NULL);
		}
		k++;
		pos += len;
	}
	words[k] = NULL;
	return (words);
}

static int word_count(char *str)
{
	int i = 0, count = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break;
		count++;
		while (str[i] != '\0' && str[i] != ' ')
			i++;
	}
	return (count);
}

static int word_len(char *str, int start)
{
	int i = start, len = 0;

	while (str[i] != '\0' && str[i] != ' ')
	{
		len++;
		i++;
	}
	return (len);
}

static char *dup_word(char *str, int start, int len)
{
	char *w;
	int i;

	w = (char *)malloc(sizeof(char) * (len + 1));
	if (w == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		w[i] = str[start + i];
	w[len] = '\0';
	return (w);
}

static void free_words(char **words, int upto)
{
	int i;

	for (i = 0; i < upto; i++)
		free(words[i]);
	free(words);
}

