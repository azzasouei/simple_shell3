#include "hsh.h"
int terminal_mode(info_t *info);
int is_delim(char c, char *delim);
int isalpha_(int c);
int _atoi(char *s);
char *begins_with(const char *str, const char *substr);
char *strcat_(char *dest, char *src);
char *strcpy_(char *dest, char *src);
char *strdup_(const char *str);
char *strchr_(char *str, char c);
char **str_to_vec(char *str);
char *memset_(char *dest, char val, unsigned int n);
void arr_free(char **arr);
void *realloc_(void *ptr, unsigned int old_size, unsigned int new_size);
int bfree(void **ptr);
/**
 * main -  initializes program state
 * and checks if it's in interactive mode
 * Return: exit success
 */
int main(void)
{
	info_t info;

	memset(&info, 0, sizeof(info_t));
	if (terminal_mode(&info))
	{
		printf("Interactive mode\n");
	}
	else
	{
		printf("Not in interactive mode\n");
	}

	return (EXIT_SUCCESS);
}
