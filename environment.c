#include "hsh.h"

/**
 * print_environment - Print the current environment.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int print_environment(info_t *info)
{
    print_list_str(info->env);
    return 0;
}

/**
 * get_environment_value - Get the value of an environment variable.
 * @info: Structure containing potential arguments.
 * @name: Env variable name.
 * Return: The value or NULL if not found.
 */
char *get_environment_value(info_t *info, const char *name)
{
    for (list_t *node = info->env; node; node = node->next)
    {
        char *p = starts_with(node->str, name);
        if (p && *p)
            return p;
    }
    return NULL;
}

/**
 * set_environment_variable - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure.
 */
int set_environment_variable(info_t *info)
{
    if (info->argc != 3)
    {
        write(2, "Incorrect number of arguments\n", 31);
        return 1;
    }

    return _setenv(info, info->argv[1], info->argv[2]) ? 0 : 1;
}

/**
 * unset_environment_variable - Remove an environment variable.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure.
 */
int unset_environment_variable(info_t *info)
{
    if (info->argc == 1)
    {
        write(2, "Too few arguments.\n", 19);
        return 1;
    }

    for (int i = 1; i < info->argc; i++)
        _unsetenv(info, info->argv[i]);

    return 0;
}

/**
 * populate_environment_list - Populate env linked list with environment variables.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure.
 */
int populate_environment_list(info_t *info)
{
    char **environ = get_environ();
    for (size_t i = 0; environ[i]; i++)
        add_node_end(&info->env, environ[i], 0);

    return 0;
}

