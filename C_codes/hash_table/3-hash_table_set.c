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
    while (k != '\0')
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
    int len, k;
    char *str_space;

    if (!str)
        return (NULL);

    k = 0;
    while (str[k] != '\0')
        k++;

    len = k + 1;
    str_space = malloc(len * sizeof(char));
    if (!str_space)
        return NULL;
    return _strcpy(str, str_space);
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
    char *val;
    unsigned long int k;

    index = hash_djb2((unsigned char *)key);
    val = _strdup(value);
    if (!val)
        return (1);

    if (!ht->array)
        return (1);

    k = 0;
    while (k < index)
        ht->array[k] = ht->array[k]->next;
    ht->array[index]->key = (char *)key;
    ht->array[index]->value = val;
    return (0);
}