#include "hash_table.h"

/**
 * hash_table_delete - deletesba hash table
 * @ht: pointer to the table
 *
 * Return: void
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current, *next;
	unsigned long int k;

	if (!ht || !ht->array || ht->size == 0)
		return;

	for (k = 0; k < ht->size; k++)
	{
		current = ht->array[k];
		while (current)
		{
			next = current->next;
			if (current->key)
			{
				free(current->key);
				current->key = NULL;
			}

			if (current->value)
			{
				free(current->value);
				current->value = NULL;
			}
			free(current);
			current = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	free(ht);
}
