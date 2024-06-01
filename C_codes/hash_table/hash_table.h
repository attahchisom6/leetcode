#ifndef __HASH__
#define __HASH__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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


/**                           * struct shash_node_s - node of a sorted hash table       * @key: non nullable string
 * @value: value to be associated with the key
 * @next: pointer to the next node
 * @snext: pointer to the nex
t sorted list
 * @prev: pointer to the prev
ious sorted list
 */

typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *snext;
	struct shash_node_s *sprev;
} shash_node_t;


/**
 * struct shash_table_s - a sorted table
 * @size: size of the array containing the nodes
 * @array: array of size @size
 * where each cell contain the head of a linked list
 * because we want our table to use chain collision
 * @shead: pointer to the first element of the sorted linked sorted linked list
 * @tail: pointer to the last element of the sorted linked list
 */

typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *stail;
	shash_node_t *shead;
} shash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

// sorted hash_table
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#endif
