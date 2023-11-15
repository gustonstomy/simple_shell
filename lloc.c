#include "shell.h"

/**
 **_memset - A function that fills memory with constant byte
 *@s: pointer to memory area
 *@b: the byte to fill
 *@n: amount of bytes to be filled
 *Return: pointer to the memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int l;

	for (l = 0; l < n; l++)
		s[l] = b;
	return (s);
}

/**
 * ffree - A function that frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **r = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(r);
}

/**
 * _realloc - A function that reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: size of previous block
 * @new_size: size of new block
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	ptr = malloc(new_size);
	if (!ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		ptr[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (ptr);
}
