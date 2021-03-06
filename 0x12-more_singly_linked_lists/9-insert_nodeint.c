#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 *
 * @head: A pointer to a pointer to a linked list.
 * @idx: An unsigned integer value.
 * @n: An integer value.
 *
 * Return: A pointer to a node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *pointer;
	unsigned int tracker;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	tracker = 0;
	pointer = *head;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	while (pointer != NULL && tracker < idx - 1)
	{
		pointer = pointer->next;
		tracker++;
	}
	if (tracker == idx - 1)
	{
		new_node->next = pointer->next;
		pointer->next = new_node;
		return (new_node);
	}
	free(new_node);
	return (NULL);
}
