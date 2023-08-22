#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void shell_loop(char **env, char *program);
/*User input*/
char *shell_read_line(void);
char **parse_line(char *cmd);
/*Command execution*/
int execute_cmd(char **av, char **env, char *program);
int execute_external(char *full_path, char **av, char **env, char *program);
int execute_builtins(char **av);
/*Builtin functions*/
int exit_builtin(char **av);
int env_builtin(char **av);
int cd_builtin(char **av);
int echo_builtin(char **av);
/*String handling functions*/
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
void free_tkns(char **tkn_str);
/*Path and env functions*/
char *get_fullpath(char *usr_cmd);
/* Typdefs and external variables */
typedef int (*func_builtin)(char **av);

#endif /* MAIN_H*/
