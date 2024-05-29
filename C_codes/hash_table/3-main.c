#include "hash_table.h"

/**
* main - driver program
*
* Return: EXIT_SUCCESS
*/

int main(void)
{
    hash_table_t *ht;
    int m;

    ht = hash_table_create(1024);
    m = hash_table_set(ht, "Betty", "Cool");
    printf("%d\n", m);

    return (EXIT_SUCCESS);
}