#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - adds element to hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key,
	const char *value)
{
	unsigned long int index;
	hash_node_t *node;
	char *val_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	node = ht->array[index];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (node->value != NULL);
		}
		node = node->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	val_copy = strdup(value);

	if (node->key == NULL || val_copy == NULL)
	{
		free(node->key);
		free(val_copy);
		free(node);
		return (0);
	}

	node->value = val_copy;
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
