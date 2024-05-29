#include "hash_table.h"

/**
* sjb3 - function to disperse a string around a point with a constant
* eveness
* @str: string argument requiring being hashed
*/

unsigned long int hash_djb2(const unsigned char *str)
{
    int c;
    int hash = 5381;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}