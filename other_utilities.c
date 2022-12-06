#include "main.h"

/**
 * _str_n_cmp - copmare n characters of 2 strings
 * @s1: first string
 * @s2: second string
 * @n: number of characters to be copied
 * Return: 0 if the same, -1 if not
 */
int _str_n_cmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
/**
 * _printenv - prints the full env variables
 * Return: 0 to end function
 */
int _printenv(void)
{
	char **env;

	env = environ;
	while (*env)
	{
		write(1, *env, sizeof(char) * _strlen(*env));
		write(1, "\n", 1);
		++env;
	}
	return (0);
}
/**
 * _getenv - gets the typed env variable by comparingthe 2 strings together
 * @name: name containg the string variable
 * Return: returns env variable path if found, otherwise NULL if not
 */
char *_getenv(char *name)
{
	char **env;
	int len = _strlen(name);

	for (env = environ; *env; ++env)
	{
		if (_str_n_cmp(name, *env, len) == 0)
			return (*env);
	}
	return (NULL);
}
/**
 * command_path - reads the path of command inputed by the user, tokenizes
 * path into a valid format, then concatenates the whole string as needed in
 * order to read full command path and returns new string
 * @cmd: command inputed
 * Return: new command path in valid format, or NULL if failed
 */
char *command_path(char *cmd)
{
	char *path = strdup(_getenv("PATH"));
	char *token = strtok(path, ":"), *new_path;
	char *path_array[100];
	struct stat buf;
	int i = 0;

	new_path = malloc(sizeof(char) * 100);
	if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (strdup(cmd));
	while (token != NULL)
	{
		path_array[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	i = 0;
	while (path_array[i] != NULL)
	{
		_strcpy(new_path, path_array[i]);
		_strcat(new_path, "/");
		_strcat(new_path, cmd);
		_strcat(new_path, "\0");
		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		i++;
	}
	free(path);
	free(new_path);
	if (stat(cmd, &buf) == 0)
		return (strdup(cmd));
	return (NULL);
}

/**
 * execute - creates the pid,
 * checks if the command exists and then executes it using execve
 * @cmd_array: array that conists the path of the command and its arguments
 * Return: 0 if command is executed properly and 1 if something went wrong
 */
int execute(char *cmd_array[])
{
	int exe, status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		return (1);
	}
	if (child_pid == 0)
	{
		if (**environ)
		{
			exe = execve(cmd_array[0], cmd_array, environ);
			if (exe == -1)
			{
				write(2, "Coulnd't find command\n", 23);
				return (1);
			}
		}
		else
		{
			exe = execve(cmd_array[0], cmd_array, NULL);
			if (exe == -1)
				write(2, "Error\n", 7);
			return (1);
		}
	}
	else
		wait(&status);
	free(cmd_array[0]);
	return (0);
}
