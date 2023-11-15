#include "shell.h"

/**
 * add_node - A function that adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Return: list size
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *nhead;

	if (!head)
		return (NULL);
	nhead = malloc(sizeof(list_t));
	if (!nhead)
		return (NULL);
	_memset((void *)nhead, 0, sizeof(list_t));
	nhead->num = num;
	if (str)
	{
		nhead->str = _strdup(str);
		if (!nhead->str)
		{
			free(nhead);
			return (NULL);
		}
	}
	nhead->next = *head;
	*head = nhead;
	return (nhead);
}

/**
 * add_node_end -A function that adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *n_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	n_node = malloc(sizeof(list_t));
	if (!n_node)
		return (NULL);
	_memset((void *)n_node, 0, sizeof(list_t));
	n_node->num = num;
	if (str)
	{
		n_node->str = _strdup(str);
		if (!n_node->str)
		{
			free(n_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_node;
	}
	else
		*head = n_node;
	return (n_node);
}

/**
 * print_list_str - A function that prints only the
 * string elements of a linked list
 * @h: pointer to first node
 * Return: list list
 */
size_t print_list_str(const list_t *h)
{
	size_t l = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		l++;
	}
	return (l);
}

/**
 * delete_node_at_index - A function that deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 or 0
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int l = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (l == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		l++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - A function that frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
