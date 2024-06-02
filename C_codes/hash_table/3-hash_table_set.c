#include "hash_table.h"

/**
* _strcpy - copy the reference of a string to another varianle
* @src: source string
* @dest: destination string
*
* Return: pointer to dest
*/

char *_strcpy(const char *src, char *dest)
{
    int k;

    k = 0;
    while (src[k] != '\0')
    {
        dest[k] = src[k];
        k++;
    }
    dest[k] = '\0';

    return dest;
}

/**
* _strdup - copies the string to a new memory location
* @src:  string to be duplicated
* 
* Return pointer to a new memory location
*/

char *_strdup(const char *str)
{
    int len;
    char *str_space;

    if (!str)
        return (NULL);

    len = 0;
    while (str[len] != '\0')
        len++;

    len++;
    str_space = malloc(len * sizeof(char));
    if (!str_space)
        return NULL;
    return _strcpy(str, str_space);
}

/**
 * _strcmp - compares two string for equality
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 of equal.
 */

int _strcmp(char *s1, char *s2)
{
	int k = 0;

	while (s1[k] != '\0' && s1[k] == s2[k])
	{
		k++;
	}
	return s1[k] - s2[k];
}

/**
* hash_table_set - dets a key, value pair in the hash table
* @ht: pointer to the head ofthe table
* @key: string key to set
* @value: corresponsing value
*
* Return: 0 on success, 1 on failure
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    char *val, *key_cpy;
    hash_node_t *new, *temp;

    if (!ht || !ht->array || !key || !*key)
	    return (0);

    val = _strdup(value);
    if (!val)
        return (0);

    key_cpy = _strdup(key);
    if (!key_cpy)
    {
        free(val);
        return (0);
    }

    index = key_index((const unsigned char *)key, ht->size);

    // we make the current entry in array at index a head of link
    temp = ht->array[index];
    while (temp)
    {
	    if (_strcmp(temp->key, (char *)key) == 0) {
		    free(temp->value);
		    temp->value = val;
            free(key_cpy);
		    return (1);
	    }
	    temp = temp->next;
    }

    // create a new node if the key doesnt exist
    new = malloc(sizeof(hash_node_t));
    if (!new)
    {
        free(key_cpy);
        free(val);
        return (0);
    }
    // i.e chain collision
    new->key = key_cpy;
    new->value = val;
    new->next = ht->array[index];
    ht->array[index] = new;
    return (1);
}
