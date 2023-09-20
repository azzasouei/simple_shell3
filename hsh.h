#ifndef _HSH_H_
#define _HSH_H_

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

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


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
char** str_to_vec(char* str);
/* memory_helper.c */
char *memset_(char *, char, unsigned int);
void arr_free(char**);
void *realloc_(void *, unsigned int, unsigned int);
int bfree(void **);
/* helper.c */
int terminal_mode(info_t *);
int is_delim(char, char *);
int isalpha_(int);
int atoi_(char *);


#endif
