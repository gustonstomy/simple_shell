#include "shell.h"

/**
 * bfree - A function that frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 * Return: 1 or 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
