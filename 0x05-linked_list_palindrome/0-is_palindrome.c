#include "lists.h"
int pali(listint_t *start, listint_t *end)
{
	int count;
	int j;

	if (end == NULL)
		return (0);
	count = pali(start, end->next);
	if (count == -1)
		return (-1);
	j = count;
	while (j != 0)
	{
		start = start->next;
		j--;
	}
	if (start->n != end->n)
		return (-1);
	return (count + 1);
}
/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: pointer
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int ret;

	if (*head == NULL)
		return (1);
	ret = pali(*head, *head);
	if (ret == -1)
		return (0);
	return (1);
}
