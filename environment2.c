#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * get_environment - Returns a copy of the string array of our environment.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
char **get_environment(info_t *info)
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
 * unset_environment_variable - Remove an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: 1 on delete, 0 otherwise
 * @var: the string representing the environment variable to be removed.
 */
int unset_environment_variable(info_t *info, char *var)
{
    if (!info->env || !var)
        return 0;

    // Create a new linked list without the variable to be unset.
    info->env = erase_environment_variable(info->env, var);

    // Update the environment change flag.
    info->env_changed = 1;

    return info->env_changed;
}

/**
 * set_environment_variable - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 * @var: the string representing the environment variable name.
 * @value: the string representing the environment variable value.
 */
int set_environment_variable(info_t *info, char *var, char *value)
{
    if (!var || !value)
        return 0;

    // Create a new environment variable string.
    char *env_var = create_environment_variable_string(var, value);

    if (!env_var)
        return 1;

    // Update the environment list.
    info->env = update_environment_variable_value(info->env, env_var);

    // Update the environment change flag.
    info->env_changed = 1;

    return 0;
}

// Helper functions using allowed functions:

void release_string_array(char **arr)
{
    if (arr)
    {
        for (size_t i = 0; arr[i]; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
}

char **convert_linked_list_to_array(list_t *env)
{
    if (!env)
        return NULL;

    size_t count = 0;
    list_t *current = env;

    // Count the number of elements in the linked list.
    while (current)
    {
        count++;
        current = current->next;
    }

    char **env_array = (char **)malloc((count + 1) * sizeof(char *));
    if (!env_array)
    {
        perror("malloc");
        return NULL;
    }

    current = env;
    size_t i = 0;

    // Copy each linked list element into the array.
    while (current)
    {
        env_array[i] = strdup(current->str);
        if (!env_array[i])
        {
            perror("strdup");
            return NULL;
        }
        i++;
        current = current->next;
    }

    env_array[i] = NULL; // Null-terminate the array.

    return env_array;
}

list_t *erase_environment_variable(list_t *env, const char *var)
{
    list_t *current = env;
    list_t *prev = NULL;

    while (current)
    {
        if (starts_with(current->str, var) && current->str[strlen(var)] == '=')
        {
            list_t *temp = current;
            current = current->next;

            if (prev)
                prev->next = current;
            else
                env = current;

            free(temp->str);
            free(temp);
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    return env;
}

char *create_environment_variable_string(const char *var, const char *value)
{
    size_t len = strlen(var) + strlen(value) + 2; // +2 for '=' and '\0'
    char *env_var = (char *)malloc(len);

    if (!env_var)
    {
        perror("malloc");
        return NULL;
    }

    snprintf(env_var, len, "%s=%s", var, value);

    return env_var;
}

list_t *update_environment_variable_value(list_t *env, const char *env_var)
{
    list_t *current = env;

    while (current)
    {
        if (starts_with(current->str, env_var))
        {
            free(current->str);
            current->str = strdup(env_var);
            if (!current->str)
            {
                perror("strdup");
                return env;
            }
            return env;
        }
        current = current->next;
    }

    // If not found, add it to the end of the list.
    add_node_end(&env, strdup(env_var), 0);
    return env;
}

