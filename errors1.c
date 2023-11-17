#include "shell.h"

/**
 * _myhistory - A function thatdisplays the history list, one command by
 *  line, preceded with line numbers, starting at 0.
 * @info:  The Structure that contains the potential arguments
 *  Return:  0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - A function that sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: 0 or 1
 */
int unset_alias(info_t *info, char *str)
{
	char *ptr, x;
	int ret;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	x = *ptr;
	*ptr = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*ptr = x;
	return (ret);
}

/**
 * set_alias - A function that sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: 0 or 1
 */
int set_alias(info_t *info, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - A function that prints an alias string
 * @node: the alias node
 * Return: 0 or 1
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *a = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (a = node->str; a <= ptr; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - A function that mimics the alias builtin
 * @info:  The Structure that contains the potential arguments
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		ptr = _strchr(info->argv[x], '=');
		if (ptr)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}
