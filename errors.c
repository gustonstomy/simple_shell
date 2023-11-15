#include "shell.h"

/**
 * _myexit - A function that exits my  shell
 * @info: The Structure that contains the potential arguments
 *  Return: returns the exit status, 0
 */
int _myexit(info_t *info)
{
	int exitstatus;

	if (info->argv[1])
	{
		exitstatus = _erratoi(info->argv[1]);
		if (exitstatus == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - A function changes the current directory of the process
 * @info:  The Structure that contains the potential arguments
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *x, *dir, buffer[1024];
	int chdir;

	x = getcwd(buffer, 1024);
	if (!x)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir = chdir(info->argv[1]);
	if (chdir == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - A function changes the current directory of the process
 * @info:  The Structure that contains the potential arguments
 *  Return: 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
