#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Add element to hash table
 * @ht: Hash table
 * @key: Key
 * @value: Value
 * Return: 1 success, 0 failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	hash_node_t *n;
	char *v;

	if (!ht || !key || !*key || !value)
		return (0);
	v = strdup(value);
	if (!v)
		return (0);
	i = key_index((unsigned char *)key, ht->size);
	n = ht->array[i];
	while (n)
	{
		if (!strcmp(n->key, key))
		{
			free(n->value);
			n->value = v;
			return (1);
		}
		n = n->next;
	}
	n = malloc(sizeof(hash_node_t));
	if (!n)
		return (free(v), 0);
	n->key = strdup(key);
	if (!n->key)
		return (free(n), free(v), 0);
	n->value = v;
	n->next = ht->array[i];
	ht->array[i] = n;
	return (1);
}
