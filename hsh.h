#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/**
 * struct liststr - Structure for a singly-linked list node
 *
 * @num: An integer element within the node.
 * @str: A pointer to a string element within the node.
 * @next: A pointer to the next node in the list.
* Description:
 * The 'list_t' structure defines a node in a singly-linked list.
 * Each node contains
 * an integer ('num') and a string ('str') element,
 * along with a pointer ('next') to
 * the next node in the list.
 * This structure is used to construct linked lists for various
 * purposes, such as storing data or building data structures.
 */


typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Information structure for a shell program
 * @arg: A pointer to a string representing a command argument.
 * @argv: A pointer to an array of
 * strings representing command arguments.
 * @path: A pointer to a string
 * representing the executable file's path.
 * @argc: An integer indicating the
 * number of command arguments.
 * @line_count: An unsigned integer
 * representing the line count.
 * @err_num: An integer for storing
 * error numbers or status codes.
 * @linecount_flag: An integer flag
 * to control line counting behavior.
 * @fname: A pointer to a string storing
 * the current file name.
 * @env: A pointer to a singly-linked
 * list of environmental variables.
 * @history: A pointer to a singly-linked
 * list for command history.
 * @alias: A pointer to a singly-linked
 * list for command aliases.
 * @environ: A pointer to an array of
 * strings for environmental variables.
 * @env_changed: An integer flag to
 * track changes in the environment.
 * @status: An integer storing the exit
 * status of the most recent command.
 * @cmd_buf: A pointer to an array of
 * strings used as a chain buffer for commands.
 * @cmd_buf_type: An integer indicating
 * the type of command (e.g., ||, &&, ;).
 * @readfd: An integer representing a file
 * descriptor for reading.
 * @histcount: An integer to keep track
 * of command history count.
 * Description:
 * The 'info_t' structure serves as a
 * container for various pieces of information
 * used in a shell program.
 * It stores details related to command arguments, execution,
 * error handling, environmental variables,
 * history, and more.
 * This structure helps manage and organize
 * data essential for shell operations.
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;


/* str_func.c */
int strlen_(char *);
int strcmp_(char *, char *);
void puts_(char *);
int putchar_(char);
/* str_func_1.c  */
char *begins_with(const char *, const char *);
char *strcat_(char *, char *);
char *strcpy_(char *, char *);
char *strdup_(const char *);
/* str_func_2.c */
char *strchr_(char *, char);
char **str_to_vec(char *str);
/* memory_helper.c */
char *memset_(char *, char, unsigned int);
void arr_free(char **);
void *realloc_(void *, unsigned int, unsigned int);
int bfree(void **);
/* helper.c */
int terminal_mode(info_t *);
int is_delim(char, char *);
int isalpha_(int);
int atoi_(char *);


#endif
