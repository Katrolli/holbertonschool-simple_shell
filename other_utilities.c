#include "main.h"

/**
 * _str_n_cmp - copmare n characters of 2 strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if the same, -1 if not 
 */
int _str_n_cmp(char *s1, char*s2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0)
}

int execute(char *cmd_array[])
{
	int exe, status, j = 0;
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }
        if (child_pid == 0)
        {
            exe = execve(argv[0], argv, NULL);
            if (exe == -1)
                printf("error");
            return (1);
            sleep(2);
        }
        else
        {
            wait(&status);
        }
	my_pid = getpid();
	if (my_pid == 0)
		printf("my_pid can't be 0");
}
