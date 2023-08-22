#include "main.h"

/**
 * exit_builtin - terminates shell programs
 * @av: command line arguments passed
 * Return: 0
 */
int exit_builtin(char **av)
{
	(void)av;
	return (0);
}

/**
 * env_builtin - prints the shell environment
 * @av: env arguments passed
 * Return: 1 on success
 */
int env_builtin(char **av)
{
	unsigned int c = 0;
	size_t len = 0;
	ssize_t byte_written;
	char *env_ptr;
	(void)av;

	while (environ[c] != NULL)
	{
		env_ptr = environ[c];
		len = _strlen(environ[c]);
		byte_written = write(STDOUT_FILENO, env_ptr, len);
		if (byte_written == -1)
		{
			perror("write");
			exit(1);
		}
		write(STDOUT_FILENO, "\n", 1);
		c++;
	}
	return (1);
}
