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
	char *token = NULL;
	int i = 0;

	if (_strcmp(s, "exit") == 0)
	{
		return (2);
	}
	if (_strcmp(s, "env") == 0)
	{
		return (_printenv());
	}
	cmd_array[0] = NULL;
	token = strtok(s, " ");
	if (token == NULL)
		return (0);
	while (token != NULL)
	{
		cmd_array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	cmd_array[i] = NULL;
	if (_strlen(cmd_array[0]) == 0)
	{
		free(cmd_array[0]);
		cmd_array[0] = NULL;
	}
	return (execute(cmd_array));
}

/**
 * main - simple shell, allocate memory to get the user input,
 * call functions to read the commands, locate them and then execute
 * Return: -1 on failure and 0 for exit
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *line = NULL;
	size_t buff_size = 0;
	ssize_t characters = 0;
	int read_value, flag;

	name = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		characters = getline(&line, &buff_size, stdin);

		if (characters == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}

		if (line[characters - 1] == '\n')
			line[characters - 1] = '\0';
		if (*line == '\0')
			continue;
		read_value = command_read(line, characters);
		if (read_value == 2 && flag != 1)
			break;
		else if (read_value == 2 && flag == 1)
			return 2;
	}
	free(line);
	line = NULL;
	return (0);
}
