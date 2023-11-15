#include "shell.h"

/**
 * **strtow - A function that splits a string into words.
 * Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: pointer to an array of strings
 */

char **strtow(char *str, char *d)
{
	int l, x, k, y, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (l = 0; str[l] != '\0'; l++)
		if (!is_delim(str[l], d) && (is_delim(str[l + 1], d) || !str[l + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (l = 0, x = 0; x < numwords; x++)
	{
		while (is_delim(str[l], d))
			l++;
		k = 0;
		while (!is_delim(str[l + k], d) && str[l + k])
			k++;
		s[x] = malloc((k + 1) * sizeof(char));
		if (!s[x])
		{
			for (k = 0; k < x; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (y = 0; y < k; y++)
			s[x][y] = str[l++];
		s[x][y] = 0;
	}
	s[x] = NULL;
	return (s);
}

/**
 * **strtow2 - A function that splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings
 */
char **strtow2(char *str, char d)
{
	int l, x, k, y, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (l = 0; str[l] != '\0'; l++)
		if ((str[l] != d && str[l + 1] == d) ||
				(str[l] != d && !str[l + 1]) || str[l + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (l = 0, x = 0; x < numwords; x++)
	{
		while (str[l] == d && str[l] != d)
			l++;
		k = 0;
		while (str[l + k] != d && str[l + k] && str[l + k] != d)
			k++;
		s[x] = malloc((k + 1) * sizeof(char));
		if (!s[x])
		{
			for (k = 0; k < x; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (y = 0; y < k; y++)
			s[x][y] = str[l++];
		s[x][y] = 0;
	}
	s[x] = NULL;
	return (s);
}
