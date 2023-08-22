#include "main.h"

/**
 * shell_loop - shell loop that shows input prompt and executes commands
 * @env: the shell evnironment variables
 * @program: the name of the shell program
 * Return: void
 */
void shell_loop(char **env, char *program)
{
	char *cmd = NULL;
	char **args = NULL;
	int status = 1;

	while (status)
	{
		write(STDIN_FILENO, "$ ", 2);
		args = NULL;
		cmd = shell_read_line();
		if (cmd == NULL)
			continue;
		args = parse_line(cmd);
		status = execute_cmd(args, env, program);

		if (cmd != NULL)
			free(cmd);
		free_tkns(args);
	}
}

/**
 * shell_read_line - reads a line and and executes it
 * Return: line read from stream or -1 on failure
 */
char *shell_read_line(void)
{
	ssize_t getline_status;
	char *cmd_buff = NULL;
	size_t bufsize = 0;

	getline_status = getline(&cmd_buff, &bufsize, stdin);
	if (getline_status == -1)
	{
		if (getline_status == EOF)
		{
			free(cmd_buff);
			exit(0);
		}
		else
		{
			perror("Getline");
			exit(1);
		}
	}
	return (cmd_buff);
}

/**
 * parse_line - tokenises the user input to an array of strings
 * @cmd: address of buffer that holds line string
 * Return: tokenized array of strings
 */
char **parse_line(char *cmd)
{
	size_t i = 0, k = 0, num_tkns = 0;
	const char *deliminator = " \n\t";
	char **tkn_str = NULL;
	char *cmd_cp = NULL, *tkn_ptr = NULL;

	cmd_cp = _strdup(cmd);
	tkn_ptr = strtok(cmd_cp, deliminator);
	while (tkn_ptr != NULL)
	{
		num_tkns++;
		tkn_ptr = strtok(NULL, deliminator);
	}
	free(cmd_cp);

	if (num_tkns != 0)
	{
		tkn_str = malloc(sizeof(char *) * (num_tkns + 1));
		if (tkn_str == NULL)
		{
			perror("Malloc");
			exit(1);
		}
		tkn_ptr = strtok(cmd, deliminator);
		while (tkn_ptr != NULL)
		{
			tkn_str[i] = _strdup(tkn_ptr);
			if (tkn_str[i] == NULL)
			{
				while (k < i)
					free(tkn_str[k]), k++;
				free(tkn_str);
				return (NULL);
			}
			i++;
			tkn_ptr = strtok(NULL, deliminator);
		}
		tkn_str[i] = NULL;
	}
	return (tkn_str);
}

/**
 * free_tkns - free all memory blocks of tknized strings
 * @tkn_str: pointer to the array of tkn pointers
 * Return: Nothing
 */
void free_tkns(char **tkn_str)
{
	size_t c;

	if (tkn_str == NULL)
		return;
	for (c = 0; tkn_str[c] != NULL; c++)
		free(tkn_str[c]);
	free(tkn_str);
}
