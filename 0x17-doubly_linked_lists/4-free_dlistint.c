#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node with the given value
 *                   at the end of a doubly linked list.
 *
 * @head: A pointer to the head of the doubly linked list.
 * @n: The value to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if allocation fails.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *current;
    dlistint_t *new_node;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    current = *head;

    if (current != NULL)
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
    else
    {
        *head = new_node;
    }

    new_node->prev = current;

    return (new_node);
}
