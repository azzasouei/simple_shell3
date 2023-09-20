#include "hsh.h"
#include <stdlib.h>
/**
 **strchr_ - locates a character in a string
 *@str: the string to be parsed
 *@c: the character to look for
 *Return:  a pointer or NULL
 */
char *strchr_(char *str, char c)
{
	while (*str++ != '\0')
	{
		if (*str == c)
		{
			return (str);
		}
		++(*str);
	}

	return (NULL);
}

/**
 * count_words - Count the number of words in a string.
 * @str: The input string.
 * @delimiter: The word delimiter.
 *
 * Return: The number of words.
 */
static int count_words(char *str, char *delimiter)
{
	int count = 0;
	int is_word = 0;

	while (*str)
	{
		if (!is_delim(*str, delimiter))
		{
			if (!is_word)
			{
				count++;
				is_word = 1;
			}
		}
		else
		{
			is_word = 0;
		}
		str++;
	}

	return (count);
}

/**
 * split_string - Split a string into an array of words.
 * @str: The input string.
 * @delimiter: The word delimiter.
 *
 * Return: An array of words.
 */
static char **split_string(char *str, char *delimiter)
{
	int num_words = count_words(str, delimiter);
	char **words = malloc(sizeof(char *) * (num_words + 1));
	int word_index = 0;
	int word_length = 0;
	int is_word = 0;

	if (num_words == 0)
	{
		return (NULL);
	}
	if (!words)
	{
		return (NULL);
	}
	while (*str)
	{
		if (!is_delim(*str, delimiter))
		{
			if (!is_word)
			{
				is_word = 1;
				word_length = 0;
				words[word_index] = str;
				word_index++;
			}
			word_length++;
		}
		else
		{
			if (is_word)
			{
				*str = '\0';
			}
			is_word = 0;
		}
		str++;
	}
	words[num_words] = NULL;
	return (words);
}
/**
 * str_to_vec - Split a string into words.
 * @str: The input string.
 *
 * Return: An array of words.
 */
char **str_to_vec(char *str)
{
	char *delimiter = " ";

	if (!str || !str[0])
	{
		return (NULL);
	}

	return (split_string(str, delimiter));
}
