#include "hsh.h"

/**
 * _exit_shell - Exits the shell.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function exits the shell with a given exit status.
 * If an exit status is provided as an argument, it is used; otherwise, it defaults to -1.
 *
 * Return: Always returns -2 to signal the shell to exit.
 */
int _exit_shell(info_t *info)
{
	if (info->argv[1])
	{
		int exit_code = _atoi(info->argv[1]);

		if (exit_code == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_code;
	} else
	{
		info->err_num = -1;
	}
	return (-2);
}

/**
 * _change_directory - Changes the current directory of the shell process.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function changes the current directory of the shell process.
 * If no directory is specified as an argument, it changes to the user's home directory.
 * If "-" is provided as an argument, it changes to the previous directory.
 *
 * Return: Always returns 0.
 */
int _change_directory(info_t *info)
{
	char buffer[1024];
	char *dir = NULL;

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			dir = _getenv(info, "PWD=");
	} else if (_strcmp(info->argv[1], "-") == 0)
	{
		dir = _getenv(info, "OLDPWD=");
		if (!dir)
		{
			_puts(getcwd(buffer, 1024));
			_putchar('\n');
			return (1);
		}
	} else
	{
		dir = info->argv[1];
	}

	if (chdir(dir) == -1)
	{
		perror("chdir");
		return (1);
	}
	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));
	return (0);
}

/**
 * _show_help - Displays a help message.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function displays a help message to provide information about the shell.
 *
 * Return: Always returns 0.
 */
int _show_help(info_t *info)
{
	_puts("Help call works. Function not yet implemented.\n");
	return (0);
}

