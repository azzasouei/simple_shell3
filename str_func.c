#include "hsh.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * strlen_- returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int strlen_(char *str)
{
	int len = 0;

	if (!str)
	{
		return (0);
	}

	while (*str++)
	{
		++len;
	}
	return (len);
}

/**
 * strcmp_ - compares two strangs.
 * @str1: the first strang
 * @str2: the second strang
 *
 * Return: negative if str1 < str2,
 * positive if str1 > str2, zero if str1 == str2
 */
int strcmp_(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		++str1;
		++str2;
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		if (*str1 < *str2)
		{
			return (-1);
		}
		else
		{
			return (1);
		}
	}
}
/**
 *puts_ - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void puts_(char *str)
{
	int idx = 0;

	if (!str)
	{
		return;
	}

	while (str[idx] != '\0')
	{
		putchar_(str[idx++]);
	}
}

/**
 * putchar_ - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putchar_(char c)
{
	static int idx;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || idx >= WRITE_BUF_SIZE)
	{
		write(1, buf, idx);
		idx = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[idx++] = c;
	}
	return (1);
}
