#include "hsh.h"

/**
 **memset_ - fills memory with a given value
 *@dest: the pointer to the memory area
 *@val: the value  to fill the memory area with
 *@n: the amount of bytes to be filled
 *Return: Pointer to the memory area
 */
char *memset_(char *dest, char val, unsigned int n)
{
	unsigned int idx;

	for (idx = 0; idx < n; ++idx)
	{
		dest[idx] = val;
	}
	return (dest);
}

/**
 * arr_free - frees an array of strings
 * @arr: array of strings
 */
void arr_free(char **arr)
{
	char **a = arr;

	if (!arr)
	{
		return;
	}

	while (*arr)
	{
		free(*arr++);
	}
	free(a);
}

/**
 * realloc_ - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the block.
 */
void *realloc_(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (!new_size)
	{
		return (free(ptr), NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}

	p = malloc(new_size);
	if (!p)
	{
		return (NULL);
	}

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		p[old_size] = ((char *)ptr)[old_size];
	}

	free(ptr);
	return (p);
}

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
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

