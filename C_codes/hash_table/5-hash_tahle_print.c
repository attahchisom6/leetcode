#include "hash_table.h"

/**
 * hash_table_print - prints a hash table
 * @ht: pointer to the head of the table
 *
 * Return: void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *temp;
	unsigned long int k;
	bool flag = true;

	if (!ht || !ht->array || ht->size == 0)
		return;

	printf("{");
	k = 0;
	while (k < ht->size)
	{
		temp = ht->array[k];
		while (temp)
		{
			if (!flag)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			flag = false;
			temp = temp->next;
		}
		k++;
	}
	printf("}\n");
}
