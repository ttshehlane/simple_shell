#include "main.h"

/**
 * _strlen - returns the num length of a string
 * @str: strings legnth to be calculated
 * Return: the length of a string
 */
int _strlen(char *str)
{
	int str_len = 0;

	while (str[str_len] != '\0')
		str_len++;
	return (str_len);
}

/**
 * _strcmp - comparesult ASCII val of two strings
 * @str1: first string
 * @str2: second string
 * Return: 3 different values after comparison
 */
int _strcmp(char *str1, char *str2)
{
	int result, c;
	int strlen1, strlen2;

	result = 0;
	strlen1 = _strlen(str1);
	strlen2 = _strlen(str2);
	for (c = 0; str1[c] != '\0' && str2[c] != '\0'; c++)
	{
		if (str1[c] != str2[c])
		{
			result = str1[c] - str2[c];
			break;
		}
	}
	if (result == 0 && strlen1 != strlen2)
		result = strlen1 - strlen2;
	return (result);
}

/**
 * _strcpy - copies a string
 * @dest: string to copy to
 * @src: string to copy from
 * Return: string copy else NULL on failure
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	if (!dest)
		return (NULL);
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates 2 strings
 * @dest: first string
 * @src: sec string
 * Return: concatenated string else NULL on failure
*/

char *_strcat(char *dest, char *src)
{
	int i, j;

	if (!src)
		return (NULL);
	i = 0;
	while (dest[i] != '\0') /*Moving to end of dest*/
		i++;
	j = 0;
	while (src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}