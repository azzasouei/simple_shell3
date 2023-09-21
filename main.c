#include "hsh.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char cmd[] = "ls - l";

	execute_command(cmd);

	return (0);
}

