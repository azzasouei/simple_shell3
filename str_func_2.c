#include "hsh.h"

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
 * **str_to_vec - splits a string into words.
 * @str: the input string
 *
 *Return: a pointer to an array of strings, or NULL.
 */
char **str_to_vec(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int number_of_words = 0;
	char *delimiter = " ";
	char **vector;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (!is_delim(str[i], delimiter) &&
				(is_delim(str[i + 1], delimiter) || !str[i + 1]))
		{
			++number_of_words;
		}
	}
	if (number_of_words == 0)
	{
		return (NULL);
	}
	vector = malloc(sizeof(char *) * (number_of_words + 1));
	if (!vector)
	{
		return (NULL);
	}
	for (i = 0, j = 0; j < number_of_words; ++j)
	{
		while (is_delim(str[i], delimiter))
		{
			++i;
		}
		k = 0;
		while (!is_delim(str[i], delimiter) && str[i + k])
		{
			++k;
		}
		vector[j] = malloc(sizeof(char) * (k + 1));
		if (!vector[j])
		{
			for (k = 0; k < j; ++k)
			{
				free(vector[k]);
			}
			free(vector);
			return (NULL);
		}
		for (m = 0; m < k; ++m)
		{
			vector[j][m] = str[i++];
		}
		vector[j][m] = 0;
	}
	vector[j] = NULL;
	return (vector);
}
