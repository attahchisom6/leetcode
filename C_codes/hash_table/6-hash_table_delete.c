#include "hash_table.h"

/**
 * hash_table_delete - deletesba hash table
 * @ht: pointer to the table
 *
 * Return: void
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp;
	unsigned long int k;

	if (!ht || !ht->array || ht->size == 0)
		return;

	for (k = 0; k < ht->size; k++)
	{
		// temp = ht->array[k];
		while ((temp = ht->array[k]))
		{
			ht->array[k] = ht->array[k]->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
	free(ht->array);
	free(ht);
}
