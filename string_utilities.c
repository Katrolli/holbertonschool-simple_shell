#include "main.h"

/**
 * _strlen - find string length
 * @str: string where to find length
 * Return: length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcat - concatenate 2 strings
 * @dest: where to add string
 * @src: string to add
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copy strings
 * @dest: where to copy strings
 * @src: string to copy
 * Return: coppied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - duplicate string
 * @str: string to duplicate
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	int i = 0;
	char *temp;

	if (str == NULL)
		return (NULL);
	temp = malloc(sizeof(char) * (_strlen(str)) + 1);
	if (temp == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/**
 * _strcmp - compare strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if the same, 1 if s1 > s2, -1 if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
