#include "hsh.h"

/**
 * printEnvironment - Print the current environment.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int printEnvironment(info_t *info)
{
print_list_str(info->env);
    return 0;
}

/**
 * getEnvironmentValue - Get the value of an environment variable.
 * @info: Structure containing potential arguments.
 * @name: Env variable name.
 * Return: The value or NULL if not found.
 */
char *getEnvironmentValue(info_t *info, const char *name)
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
 * setEnvironmentVariable - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure.
 */
int setEnvironmentVariable(info_t *info)
{
    if (info->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return 1;
    }
    
    return _setenv(info, info->argv[1], info->argv[2]) ? 0 : 1;
}

/**
 * unsetEnvironmentVariable - Remove an environment variable.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure.
 */
int unsetEnvironmentVariable(info_t *info)
{
    if (info->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return 1;
    }
    
    for (int i = 1; i < info->argc; i++)
        _unsetenv(info, info->argv[i]);
    
    return 0;
}

/**
 * populateEnvironmentList - Populate env linked list with environment variables.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure.
 */
int populateEnvironmentList(info_t *info)
{
    for (size_t i = 0; environ[i]; i++)
        add_node_end(&info->env, environ[i], 0);
    
    return 0;
}

