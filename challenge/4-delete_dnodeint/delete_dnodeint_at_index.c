#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* find the node at index */
	tmp = *head;
	while (tmp != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	/* index out of range */
	if (tmp == NULL)
		return (-1);

	/* unlink tmp */
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	else
		/* deleting head */
		*head = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);

	return (1);
}
