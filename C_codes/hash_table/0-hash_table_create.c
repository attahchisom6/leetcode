#include "hash_table.h"

/**
* hash_table_create - create anempty hash table
* @size: size of the hash table
* 
* Return: pointer to the created hash table
*/

hash_table_t *hash_table_create(unsigned long int size) {
    hash_table_t *table;
    unsigned long int k;

    table = malloc(sizeof(hash_table_t));
    if (!table)
        return NULL;

    table->size = size;
    table->array = malloc(size * sizeof(hash_node_t *));
    if (!table->array) {
        free(table);
        return NULL;
    }

    k = 0;
    while (k < size) {
        table->array[k] = NULL;
        k++;
    }
    return table;
}