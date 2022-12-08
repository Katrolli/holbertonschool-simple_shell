#include "main.h"

/**
 * command_read - reads user input, tokenizes the string and fills up the array
 * @s: user command input
 * @characters: len of s
 * Return: int of execute function
 */
int command_read(char *s, size_t __attribute__((unused)) characters)
{
	char *cmd_array[100];
	const char delim[2] = " ";
	char *token, *temp;
	int i = 0;

	if (_strlen(s) == 0)
		return (0);
	temp = _strdup(s);
	if (_strcmp(temp, "exit") == 0)
	{
		free(temp);
		exit (0);
	}
	if (_strcmp(temp, "env") == 0)
	{
		free(temp);
		return (_printenv());
	}
	cmd_array[0] = NULL;
	token = strtok(temp, delim);
	while (token != NULL)
	{
		cmd_array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	if (cmd_array[0] == NULL)
	{
		free(temp);
		return (0);
	}
	cmd_array[i] = NULL;
	return (execute(cmd_array));
}

/**
 * main - simple shell, allocate memory to get the user input,
 * call functions to read the commands, locate them and then execute
 * Return: -1 on failure and 0 for exit
 */
int main(void)
{
	char *buffer;
	size_t characters, size = 1024;
	size_t i = 0, j = -1;

	buffer = (char *)malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		free(buffer);
		return (-1);
	}
	while (i < 1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		characters = getline(&buffer, &size, stdin);
		if (characters == j)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "Unexplained Error", 18);
			break;
		}
		if (*buffer == '\0')
			continue;
		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = '\0';
		if (command_read(buffer, characters) == 2)
		{
			free(buffer);
			buffer = NULL;
			return (2);
		}
	}
	free(buffer);
	buffer = NULL;
	return (0);
}
