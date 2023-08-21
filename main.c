#inlcude "main.h"

/**
 * main - program entry
 * @argc: num of args
 * @argv: array of cmd args
 * Return: 0 on success or 1 on failure
 */
int main(int argc, char **argv)
{
	char **arg = NULL;
	char **env = environ;
	unsigned in i = 1;

	if (isatty(STDIN_FILENO) && argc > 1)
	{
		arg = &argv[i];
		execute_cmd(arg, env, arg[0]);
	}
	else
		shell_loop(env, argv[0]);
	return (0);
}
