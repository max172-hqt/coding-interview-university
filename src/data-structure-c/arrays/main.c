#include <stdio.h>
#include <assert.h>
#include "arrays.h"
#define INIT_SIZE 4

int main(void)
{
    list *list = create_new(INIT_SIZE);
    push(list, 10);
    push(list, 11);
    push(list, 12);

    assert(size(list) == 3);
    assert(!is_empty(list));

    assert(at(list, 0) == 10);
    assert(at(list, 1) == 11);
    assert(at(list, 2) == 12);
    at(list, 4);

    push(list, 13);
    assert(size(list) == 4);

    /* print_debug(list); */

    push(list, 14);
    assert(size(list) == 5);
    assert(capacity(list) == 8);
    push(list, 15);
    push(list, 16);

    print_debug(list);
    assert(at(list, 0) == 10);

    free(list->items);
    free(list);

    return 0;
}
