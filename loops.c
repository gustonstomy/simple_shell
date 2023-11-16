#include "shell.h"

/**
 * hsh -The main shell loop
 * @info: return info of struct
 * @av: the argument vector from main
 * Return: 0 or 1
 */
int hsh(info_t *info, char **av)
{
	ssize_t l = 0;
	int builtin_ret = 0;

	while (l != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		l = get_input(info);
		if (l != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - A function that finds a builtin command
 * @info: parameter and return info struct
 * Return: 1
 */
int find_builtin(info_t *info)
{
	int l, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}};

	for (l = 0; builtintbl[l].type; l++)
		if (_strcmp(info->argv[0], builtintbl[l].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[l].func(info);
			break;
		}
	return (built_in_ret);
}

