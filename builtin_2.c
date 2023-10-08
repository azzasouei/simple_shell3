#include "shell.h"

/**
 * my_custom_exit - Exit the shell or set the exit status
 * @info: Structure containing potential arguments
 * Return: Always returns -2 to indicate the shell should exit
 */
int my_custom_exit(info_t *info)
{
	if (info->args[1])
	{
		info->exit_status = _erratoi(info->args[1]);
		if (info->exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->args[1]);
			_eputchar('\n');
			return (1);
		}
	}
	else
		info->exit_status = -1;
	return (-2);
}

/**
 * my_custom_cd - Change the current directory of the process
 * @info: Structure containing potential arguments
 * Return: Always returns 0
 */
int my_custom_cd(info_t *info)
{
	char *new_dir = info->args[1];
	char *old_pwd = _getenv(info, "PWD=");
	int chdir_ret;

	if (!new_dir)
		new_dir = _getenv(info, "HOME=");

	if (_strcmp(new_dir, "-") == 0)
		new_dir = old_pwd;

	chdir_ret = chdir(new_dir);

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(new_dir), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", old_pwd ? old_pwd : "");
		_setenv(info, "PWD", getcwd(NULL, 0));
	}

	return (0);
}

/**
 * my_custom_help - Display help information
 * @info: Structure containing potential arguments
 * Return: Always returns 0
 */
int my_custom_help(info_t *info)
{
	(void)info; /* Avoid unused variable warning */
	_puts("Help: Not yet implemented\n");
	return (0);
}

