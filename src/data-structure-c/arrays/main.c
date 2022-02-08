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

    assert(at(list, 0) == 10);

    /* insert(list, 7, 9); */
    prepend(list, 100);
    print_debug(list);

    printf("%d\n", pop(list));
    pop(list);
    /* pop(list); */
    /* pop(list); */
    /* pop(list); */
    /* pop(list); */
    /* print_debug(list); */
    /* prepend(list, 100); */
    /* prepend(list, 100); */
    /* prepend(list, 100); */

    delete(list, 2);
    print_debug(list);
    my_remove(list, 12);
    print_debug(list);

    free(list->items);
    free(list);
    return 0;
}
