#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * insert_node - function that inserts a number into
 * a sorted singly linked list
 * @head: first node
 * @number: element
 * Return: the address of the new node or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node;
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = number;

	if (*head == NULL || (*head)->n >= new_node->n)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		node = *head;
		while (node->next != NULL && node->next->n < new_node->n)
			node = node->next;
		new_node->next = node->next;
		node->next = new_node;
	}
	return (new_node);
}
