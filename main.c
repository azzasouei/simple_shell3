#include "hsh.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

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
 * main - Simple UNIX-like shell
 * Return: 0
 */
int main(int argc , char* argv )
{
	char input[MAX_INPUT_LENGTH];
	int status;
	pid_t pid = fork();

	for (;;)
	{
		printf("simple> ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\nExiting simple_shell.\n");
			break;
		}
	}
	input[strcspn(input, "\n")] = '\0';

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execlp(input, input, NULL) == -1)
		{
			perror("Exec error");
			exit(EXIT_FAILURE);
		}
	} else
	{
		wait(&status);
	}
	return (0);
}
