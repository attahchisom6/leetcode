#include "hash_table.h"

/**
 * hash_table_get - retrieve a value in the hash table
 * if the key exists
 * @ht: pointer to the head of the table
 * @key: whose value we seek to retrieve
 *
 * Return: pointet to the value if it sure exist
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *temp;
	unsigned long int  index;

	index = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[index];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0) {
			return temp->value;
		}
		temp = temp->next;
	}
	return NULL;
}
