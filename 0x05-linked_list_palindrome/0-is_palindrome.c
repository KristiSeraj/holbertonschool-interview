#include "lists.h"
/**
 * reverse - function that reverses linked list
 * @head: pointer
 * Return: prev node
 */
listint_t *reverse(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *temp = NULL;

	while (head)
	{
		temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}
	return (prev);
}
/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: pointer
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast;

	slow = *head;
	fast = *head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	slow = reverse(slow);
	while (slow)
	{
		if ((*head)->n != slow->n)
			return (0);
		*head = (*head)->next;
		slow = slow->next;
	}
	return (1);
}
