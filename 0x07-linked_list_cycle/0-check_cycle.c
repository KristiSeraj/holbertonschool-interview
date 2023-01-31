#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: head
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *prev = list;
	listint_t *node = list;

	while (prev && node && node->next)
	{
		prev = prev->next;
		node = node->next->next;
		if (node == prev)
		{
			return (1);
		}
	}
	return (0);
}
