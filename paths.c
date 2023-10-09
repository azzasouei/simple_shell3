#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main(void) {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH / 2];
    
    while (1) {
        printf("$ ");  // Display a shell prompt
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Error reading user input");
            exit(EXIT_FAILURE);
        }

        // Remove the newline character
        size_t input_length = strlen(input);
        if (input_length > 0 && input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }

        // Split the input into arguments
        char *token = strtok(input, " ");
        int arg_count = 0;

        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        if (arg_count > 0) {
            if (strcmp(args[0], "exit") == 0) {
                exit(0);  // Exit the shell
            } else if (strcmp(args[0], "cd") == 0) {
                // Change directory
                if (arg_count == 2) {
                    if (chdir(args[1]) != 0) {
                        perror("cd");
                    }
                } else {
                    fprintf(stderr, "Usage: cd <directory>\n");
                }
            } else {
                pid_t child_pid = fork();

                if (child_pid == -1) {
                    perror("Error creating a new process");
                    exit(EXIT_FAILURE);
                }

                if (child_pid == 0) {
                    // In the child process, execute the command
                    execvp(args[0], args);
                    perror("Error executing the command");
                    exit(EXIT_FAILURE);
                } else {
                    // In the parent process, wait for the child to complete
                    int status;
                    waitpid(child_pid, &status, 0);
                }
            }
        }
    }

    return 0;
}

