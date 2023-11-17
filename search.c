#include "shell.h"

/**
 * is_cmd - A function that determines if a file is an executable file
 * @info: the info struct
 * @path: path to the file
 * Return: 1 or 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat stru;

	(void)info;
	if (!path || stat(path, &stru))
		return (0);

	if (stru.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - A function that duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 * Return: new buffer pointer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int l = 0, k = 0;

	for (k = 0, l = start; l < stop; l++)
		if (pathstr[l] != ':')
			buf[k++] = pathstr[l];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 * Return: full path or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int l = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[l] || pathstr[l] == ':')
		{
			path = dup_chars(pathstr, curr_pos, l);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[l])
				break;
			curr_pos = l;
		}
		l++;
	}
	return (NULL);
}
