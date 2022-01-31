#include <stdlib.h>
#include "arrays.h"

list* create_new(int capacity)
{
    list *l = (list*)malloc(sizeof(list));
    l->size = 0;
    l->capacity = capacity;
    l->items = (int*)malloc(sizeof(int) * capacity);

    return l;
}

void push(list* list, int value)
{
    // Address of the next empty slot in list->items
    int *i = list->items + list->size;
    /* list->items[list->size] = value; */
    *i = value;
    list->size++;

    // TODO: Resize array if needed
}

void print_debug(list* list)
{
    printf("\nsize: %d\n", list->size);
    printf("capacity: %d\n", list->capacity);
    printf("address of first item: %p\n", list->items);
    // TODO: print out item
    int i;

    for (i = 0; i < list->size; i++) {
        printf("%d - ", *(list->items++));
    }
    printf("\n");
}
