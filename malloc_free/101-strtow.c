#include "main.h"
#include <stdlib.h>

/* Helpers prototypes (file-local) */
static int word_count(char *str);
static int word_len(char *str, int start);
static char *dup_word(char *str, int start, int len);
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

/* ===== helpers ===== */

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

