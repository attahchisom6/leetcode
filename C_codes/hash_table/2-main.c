#include "hash_table.h"

/**
* main - driver program
* 
* Return: void
*/

int main(void)
{
    char *key;
    unsigned long table_size = 1024;

    key = "C is fun";
    printf("%lu\n", hash_djb2((unsigned char *)key));
    printf("%lu\n", key_index((unsigned char *)key, table_size));

    key = "Python is cool";
    printf("%lu\n", hash_djb2((unsigned char *)key));
    printf("%lu\n", key_index((unsigned char *)key, table_size));

    key = "98";
    printf("%lu\n", hash_djb2((unsigned char *)key));
    printf("%lu\n", key_index((unsigned char *)key, table_size));

    return (EXIT_SUCCESS);

}