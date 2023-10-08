#include "hsh.h"

/**
 * _myexit - exit the shell
 * @info: Structure containing potential arguments.
 * Return: Exits with a given exit status
 */
int _myexit(info_t *info)
{
	if (info->argv[1])
	{
		int exit_code = _erratoi(info->argv[1]);

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
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _mycd(info_t *info)
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
 * _myhelp - displays a help message
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	_puts("Help call works. Function not yet implemented.\n");
	return (0);
}
