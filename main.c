#include "main.h"

/**
 * main - shell program entry
 * @argc: number of arguments
 * @argv: array of command arguments
 * Return: 0 on success run or 1 on failure
 */
int main(int argc, char **argv)
{
	char **arg = NULL;
	unsigned int i = 1;
	char **env = environ;

	if (argc && isatty(STDIN_FILENO) > 1)
	{
		arg = &argv[i];
		execute_cmd(arg, env, arg[0]);
	}
	else
		shell_loop(env, argv[0]);
	return (0);
}
