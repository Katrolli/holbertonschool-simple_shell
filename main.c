#include "main.h"

/**
 * command_read - reads user input, tokenizes the string and fills up the array
 * @s: user command input
 * @characters: len of s
 * Return: int of execute function
 */
int command_read(char *s, int __attribute__((unused)) characters)
{
	char *cmd_array[100];
	char *tmp[100];
	const char delim[2] = " ";
	char *token, *temp;
	int i = 0, j = 0;

	temp = _strdup(s);
	if (_strcmp(temp, "exit") == 0)
		return (2);
	if (_strcmp(temp, "env") == 0)
		return (_printenv());
	token = strtok(temp, delim);
	while (token != NULL)
	{
		cmd_array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	cmd_array[i] = NULL;
	while (cmd_array[j] != NULL)
	{
		if (j == 0)
			tmp[j] = command_path(cmd_array[0]);
		else
			tmp[j] = cmd_array[j];
		j++;
	}
	tmp[j] = NULL;
	return (execute(tmp));
}

/**
 * main - simple shell, allocate memory to get the user input, call functions to read the commands, locate them and then execute
 * Return: -1 on failure and 0 for exit
 */
int main(void)
{
	char *buffer;
	size_t characters, size = 1024;
	size_t i = 0, j = -1;

	buffer = (char *)malloc(sizeof(char) * size);
	if (buffer == NULL)
		return (-1);
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
			return (0);
	}
	free(buffer);
	buffer = NULL;
	return (0);
}
