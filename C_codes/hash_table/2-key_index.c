#include "hash_table.h"

unsigned long int _mod(unsigned long int hash, unsigned long int size);
/**
* key_index - Retrieve the index of the  key, value pair from the
* hash_table
* @key: key whose index is sought
* @size: size of the hash table
*
* Return; index of key
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash;

    hash = hash_djb2(key);
    return _mod(hash, size);
}


/**
* _mod - calculates the mod of two number
* hash: the number derived from a hash functin
* size:     The divisor derived from the table size
*
* Return: the modulus of the two number
*/
unsigned long int _mod(unsigned long int hash, unsigned long int size)
{
    unsigned long int res;
    unsigned long div;

    if (size == 0)
        return (0);

    div = hash / size;
    res = hash - (div * size);

    return res;
}