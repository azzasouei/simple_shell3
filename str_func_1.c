#include "hsh.h"
/**
 * begins_with - checks if string starts with substring
 * @str: string to search
 * @substr: the substring to find
 *
 * Return: address of next char of the string or NULL
 */
char *begins_with(const char *str, const char *substr)
{
	while (*substr)
	{
		if (*substr++ != *str++)
		{
			return (NULL);
		}
	}

	return ((char *)str);
}

/**
 * strcat_ - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to destination buffer
 */
char *strcat_(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = *src;

	return (ret);
}

/**
 * strcpy_ - copies a string
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to destination string
 */
char *strcpy_(char *dest, char *src)
{
	int idx = 0;

	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[idx])
	{
		dest[idx] = src[idx];
		++idx;
	}
	dest[idx] = 0;
	return (dest);
}

/**
 * strdup_ - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *strdup_(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
	{
		++length;
	}

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
	{
		return (NULL);
	}
	for (length++; length--;)
	{
		ret[length] = *--str;
	}
	return (ret);
}
