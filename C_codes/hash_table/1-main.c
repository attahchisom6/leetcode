#include "hash_table.h"

/**
* main - driver program
*
* Return: 0
*/

int main(void)
{
    char *s;

    s = "C is fun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    s = "Python is cool";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));

    return (0);
}

