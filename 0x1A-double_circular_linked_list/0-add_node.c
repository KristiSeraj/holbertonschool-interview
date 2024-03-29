#include "list.h"
/**
 * create_node - create a new node
 * @str: string
 * Return: Address of the new node, or NULL on failure
*/
List *create_node(char *str)
{
    List *new_node = malloc(sizeof(List));

    if (new_node == NULL)
    {
        return (NULL);
    }
    new_node->str = strdup(str);
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}
/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: list
 * @str: string
 * Return: Address of the new node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
    List *new_node = create_node(str);

    if (new_node == NULL)
    {
        return (NULL);
    }
    if (*list == NULL)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        *list = new_node;
    }
    else
    {
        List *last_node = (*list)->prev;
        new_node->prev = last_node;
        new_node->next = *list;
        last_node->next = new_node;
        (*list)->prev = new_node;
    }
    return (new_node);
}
/**
 * add_node_begin - Add a new node to the beginning of a double circular linked list
 * @list: list
 * @str: string
 * Return: Address of the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
    List *new_node = create_node(str);

    if (new_node == NULL)
    {
        return (NULL);
    }
    if (*list == NULL)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
    }
    else
    {
        List *first_node = *list;
        List *last_node = (*list)->prev;
        
        new_node->prev = last_node;
        new_node->next = first_node;
        first_node->prev = new_node;
        last_node->next = new_node;
    }
    *list = new_node;

    return (new_node);
}
