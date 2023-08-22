#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicate of a string to a newly alloacted memory
 * @str: pointer to a string
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	char *destination = NULL;
	unsigned int ln = 0;

	if (str == NULL)
		return (NULL);

	ln = _strlen(str) + 1;
	destination = malloc(sizeof(char) * ln);
	if (destination == NULL)
		return (NULL);
	destination = _memcpy(destination, str, ln);
	return (destination);
}
/**
 * _memcpy - copies n characters from existing memory src to memory destination
 * @dest: pointer to the destination memory area where content is to be copied
 * @src: pointer to the source of memory to be copied
 * @n: the num bytes to be copied
 * Return: Pointer to destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int c = 0;

	for (c = 0; c < n; c++)
		dest[c] = src[c];
	return (dest);
}
