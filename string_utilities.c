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
	}
	return dest[i];
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

	temp = malloc(sizeof(char) * _strlen(str));
	if (temp == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
}

/**
 * _strcmp - compare strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if the same, 1 if s1 > s2, -1 if s1 < s2
 */
int *_strcmp(char *s1, char *s2)
{
	int i = 0, len1, len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	if (len1 > len2)
		return (1);
	else if (len1 < len2)
		return (-1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
