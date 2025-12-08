#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key to look for
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	/* Check for NULL pointers and empty key */
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Get the index for the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at the index */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	/* Key not found */
	return (NULL);
}
