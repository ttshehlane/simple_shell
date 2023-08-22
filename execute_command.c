#include "main.h"

/**
 * execute_cmd - Executes built-in commands and also executes external commands
 * @av: array of command arguments to be executed
 * @env: our shells environment vairables
 * @program: the program name
 * Return: 0 on successful compilation and -1 on failure
 */
int execute_cmd(char **av, char **env, char *program)
{
	int status = 0;
	char *full_path = NULL;
	char **avCpy = NULL;

	if (av == NULL)
		return (-1);
	status = execute_builtins(av);
	if (status != -1)
		return (status); /*A builtin function is found*/
	full_path = get_fullpath(av[0]);
	if (full_path != NULL)
	{
		if (av[1] == NULL)
		{
			status = execute_external(full_path, av, env, program);
			free(full_path);
			return (status);
		}
		avCpy = &(av[1]);
		status = execute_external(full_path, avCpy, env, program);
		free(full_path);
		return (status);
	}
	perror(program);
	return (-1);
}

/**
 * execute_builtins - Looks for matching built-in function and executes it
 * @av: string array of command arguments to be executed
 * Return: 1 on success and -1 on failure
 */
int execute_builtins(char **av)
{
	int c = 0;

	func_builtin builtIns[] = {
		exit_builtin,
		env_builtin
	};
	char *builtin_cmds[] = {
		"exit",
		"env",
		NULL
	};

	for (c = 0; builtin_cmds[c] != NULL; c++)
	{
		if (_strcmp(av[0], builtin_cmds[c]) == 0)
		{
			return (builtIns[c](av));
		}
	}
	return (-1);
}

/**
 * execute_external - process gets created to execute a non-built-in command
 * @full_path: absolute full path to the location of the program
 * @av: string array of command arguments to be ran
 * @env: machine environment vaariable
 * @program: name of the program
 * Return: 1 on successful compilation and exit on failure
 */
int execute_external(char *full_path, char **av, char **env, char *program)
{
	int status = 0;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror(program);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(full_path, av, env) == -1)
		{
			perror(program);
			exit(1);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror(program);
			exit(-1);
		}
	}
	return (1);
}
