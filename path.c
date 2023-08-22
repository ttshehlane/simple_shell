#include "main.h"

/**
 * get_fpath - helper function that concats user input and path
 * @temp: temp path
 * @usr_cmd: command to be executed
 * Return: pointer to path or NULL on failure
 */
char *get_fpath(char *temp, char *usr_cmd)
{
	size_t totalLen = 0;
	char *concated = NULL;

	totalLen = totalLen + strlen(temp) + strlen(usr_cmd) + 2;
	concated = malloc(totalLen);
	if (concated == NULL)
	{
		return (NULL);
	}
	strcpy(concated, temp);
	strcat(concated, "/");
	strcat(concated, usr_cmd);
	return (concated);
}
/**
* get_fullpath - retrieves the full absolute full path
* @usr_cmd: user input command
* Return: pointer and NULL on failure
*/
char *get_fullpath(char *usr_cmd)
{
	char *path = getenv("PATH");
	char *temp = NULL;
	char *fullpath = NULL;
	char *temp_copy = strdup(path);

	if (temp_copy == NULL)
		return (NULL);
	if (access(usr_cmd, F_OK) != -1)
	{
		fullpath = strdup(usr_cmd);
		free(temp_copy);
		return (fullpath);
	}
	temp = strtok(temp_copy, ":");
	while (temp != NULL)
	{
		fullpath = get_fpath(temp, usr_cmd);
		if (access(fullpath, F_OK) != -1)
		{
			free(temp_copy);
			return (fullpath);
		}
		free(fullpath);
		temp = strtok(NULL, ":");
	}
	free(temp_copy);
	return (NULL);
}
