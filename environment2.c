#include "shell.h"

/**
 * retrieve_environment - Returns a copy of the string array of our environment.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
char **retrieve_environment(info_t *info)
{
    // Check if the environment needs to be updated.
    if (!info->environment || info->env_changed)
    {
        // Free the previous environment.
        release_string_array(info->environment);

        // Convert the linked list of environment variables to a string array.
        info->environment = convert_linked_list_to_array(info->env);

        // Reset the environment change flag.
        info->env_changed = 0;
    }

    return info->environment;
}

/**
 * remove_environment_variable - Remove an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: 1 on delete, 0 otherwise
 * @var: the string representing the environment variable to be removed.
 */
int remove_environment_variable(info_t *info, char *var)
{
    if (!info->env || !var)
        return 0;

    // Create a new linked list without the variable to be unset.
    info->env = erase_env_var(info->env, var);

    // Update the environment change flag.
    info->env_changed = 1;

    return info->env_changed;
}

/**
 * modify_environment_variable - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 * @var: the string representing the environment variable name.
 * @value: the string representing the environment variable value.
 */
int modify_environment_variable(info_t *info, char *var, char *value)
{
    if (!var || !value)
        return 0;

    // Create a new environment variable string.
    char *env_var = create_env_variable_string(var, value);

    if (!env_var)
        return 1;

    // Update the environment list.
    info->env = update_env_variable_value(info->env, env_var);

    // Update the environment change flag.
    info->env_changed = 1;

    return 0;
}

