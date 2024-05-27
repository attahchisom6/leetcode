#include "hash_table.h"

int main(void)
{
    hash_table_t *table;

    table = hash_table_create(1024);
    printf("%p\n", (void *)table);
    return (EXIT_SUCCESS);
}