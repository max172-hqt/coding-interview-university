#include <stdio.h>
#include <assert.h>
#include "arrays.h"
#define INIT_SIZE 4

int main(void)
{
    list* list = create_new(INIT_SIZE);
    push(list, 10);
    print_debug(list);

    return 0;
}
