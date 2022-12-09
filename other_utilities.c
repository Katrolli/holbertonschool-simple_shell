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
	int len = _strlen(name);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_str_n_cmp(environ[i], name, len) == 0)
			return (&environ[i][len]);
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
	char *path = _strdup(_getenv("PATH"));
	char *token = strtok(path, ":"), *new_path;
	char *path_array[100];
	struct stat buf;
	int i = 0;

	if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (_strdup(cmd));
	new_path = malloc(sizeof(char) * 100);
	while (token != NULL)
	{
		path_array[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	path_array[i] = NULL;
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
		else
			new_path[0] = 0;
		i++;
	}
	free(path);
	free(new_path);
	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));
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
	char *exe_path = NULL;
	char *cmd = NULL;
	pid_t pid;
	int status;

	cmd = cmd_array[0];
	exe_path = command_path(cmd);
	if (exe_path == NULL)
	{
		write(2, "./hsh: 1: ", 10);
		write(2, _strcat(cmd, ": not found\n"), _strlen(cmd) + 12);
		exit (127);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error creating child\n");
		return (-1);
	}
	if (pid > 0)
		wait(&status);
	else if (pid == 0)
	{
		if (environ)
		{
			execve(exe_path, cmd_array, environ);
			perror("Error");
			exit(1);
		}
		else
			execve(exe_path, cmd_array, NULL);
	}
	free(exe_path);
	return (0);
}
