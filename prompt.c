#include "hsh.h"

#define MAX_INPUT_LENGTH 1024
/**
 * main - Simple UNIX-like shell
 * Return: 0
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	int status;

	for (;;)
	{
		printf("simple_shell> ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\nExiting simple_shell.\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';

		pid_t pid = fork();

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
	}
	return (0);
}
