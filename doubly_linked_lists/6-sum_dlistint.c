#include "lists.h"

/**
 * sum_dlistint - returns the sum of all n in a dlistint_t list
 * @head: pointer to head of list
 *
 * Return: sum of all nodes, or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
