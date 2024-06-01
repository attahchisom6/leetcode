#include "hash_table.h"

/**
 * shash_table_create - creates a sorted hash_table
 * @size: size of the hash yable
 *
 * Return: pointer to the head of the table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *stable;
	unsigned long int k;

	if (!size)
		return NULL;

	stable = malloc(sizeof(shash_table_t));
	if (!stable)
		return NULL;

	stable->size = size;
	stable->array = malloc(size * sizeof(hash_node_t *));
	if (!stable->array)
	{
		free(stable);
		return (NULL);
	}

	for (k = 0; k < size; k++)
		stable->array[k] = NULL;

	stable->shead = NULL;
	stable->stail = NULL;

	return stable;
}


/**
 * shash_table_set - set key value pair in a sorted hash yable
 * @ht: pointer to the jead of the table
 * @key: non nullable string
 * @value: value associated to the string
 *
 * Return: 1 on success, 0 on failure
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *temp, *new, *curr;
	char *key_cpy, *val;
	unsigned long int idx;

	if (!ht || !key || !*key)
		return (0);

	val = strdup(value);
	if (!val)
		return (0);

	key_cpy = strdup(key);
	if (!key_cpy)
	{
		free(val);
		return (0);
	}

	idx = key_index((const unsigned char *)key, ht->size); 
	temp = ht->array[idx];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = val;
			free(key_cpy);
			return (1);
		}
		temp = temp->next;
	}

	new = malloc(sizeof(shash_node_t));
	if (!new)
	{
		free(val);
		free(key_cpy);
		return (0);
	}

	new->key = key_cpy;
	new->value = val;
	new->next = ht->array[idx];
	ht->array[idx] = new;

	if (ht->shead == NULL)
	{
		new->snext = NULL;
		new->sprev = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else
	{
		// sorting is by first char in the key
		curr = ht->shead;
		while (curr && strcmp(curr->key, new->key) < 0)
			curr = curr->snext;

		// new key is smaller than shead key
		if (curr == ht->shead)
		{
			new->snext = ht->shead;
			new->sprev = NULL;
			ht->shead->sprev = new;
			ht->shead = new;
		}

		// new key is larger than all existing keys
		else if (!curr)
		{
			new->snext = NULL;
			new->sprev = ht->stail;
			ht->stail->snext = new;
			ht->stail = new;
		}

		// new key is smaller and karger than somekey
		else
		{
			new->snext = curr;
			new->sprev = curr->sprev;
			curr->sprev->snext = new;
			curr->sprev = new;
		}
	}
	return (1);
}


/**
 * shash_table_print - prints the content of the table
 * @ht: pointer to the head the table
 *
 * Return: void
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	bool put_delim = true;

	if (!ht->size || !ht)
		return;

	printf("{");
	temp = ht->shead;;
	while (temp)
	{
		if (put_delim == false)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		put_delim = false;
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print the element in reverse order
 * @ht: pointer to the sorted table
 *
 * Return: Void
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	bool put_delim = true;

	if (!ht)
		printf("{}\n");

	printf("{");
	temp = ht->stail;
	while (temp)
	{
		if (!put_delim)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		put_delim = false;
		temp = temp->sprev;
	}
	printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr, *next;
	unsigned long int k;

	if (!ht)
		return;

	for (k = 0; k < ht->size; k++)
	{
		curr = ht->array[k];
		while (curr)
		{
			next = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			curr = next;
		}
	}

	curr = ht->shead;
	while (curr)
	{
		next = curr->snext;
		free(curr->key);
		free(curr->value);
		free(curr);
		curr = next;
	}
	free(ht->array);
	free(ht);
	ht = NULL;
}
