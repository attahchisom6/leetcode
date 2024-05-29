#ifndef __HASH__
#define __HASH__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* hash_node_s - struct defining each node in the table
* @key: string - each key is unique
* @value: string - value associated to each key
@next: pointer to the next node
*/

typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;


/**
* hash_table_s - defines the hash table
@ size: size  of the table
@ array: An array that defines the table - each cell is pointer
* to a node
*/

typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

#endif