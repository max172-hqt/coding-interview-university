#include "arrays.h"

list* create_new(int capacity)
{
    list *l = (list*)malloc(sizeof(list));
    check_address(l);
    l->size = 0;
    l->capacity = capacity;
    l->items = (int*)malloc(sizeof(int) * capacity);
    check_address(l->items);

    return l;
}

void push(list *list, int value)
{
    if (list->size >= list->capacity) {
        resize(list, list->capacity * 2);
    }
    *(list->items + list->size) = value;
    list->size++;
}

int size(list *list)
{
    return list->size;
}

int capacity(list *list)
{
    return list->capacity;
}

bool is_empty(list *list)
{
    return list->size == 0;
}

int at(list *list, int index)
{
    if (index >= list->size) {
        printf("Index out of bounds\n");
        return '\0';
    }
    int *item = list->items + index;
    return *item;
}

void resize(list *list, int capacity)
{
    int i;
    int *old;
    int *new;
    // Allocate bigger chunk of memory
    /* int *list_temp = (int*)malloc(sizeof(int) * capacity); */
    int *list_temp = (int*)realloc(list->items, sizeof(int) * capacity); 
    check_address(list_temp);

    /* i = 0; */
    /* while (i < list->size) { */
    /*     old = list->items + i; */
    /*     new = list_temp + i; */
    /*     *new = *old; */
    /*     printf("%p %d ", new, *new); */
    /*     i++; */
    /* } */

    list->capacity = capacity;
    list->items = list_temp;
}

void insert(list *list, int index, int value)
{
    if (index >= list->size) {
        printf("Error: Invalid index\n");
        exit(EXIT_FAILURE);
    }
    if (list->size >= list->capacity) {
        resize(list, list->capacity * 2);
    }

    // Shift right
    int i;
    for (i = list->size; i >= index; i--) {
        *(list->items + i + 1) = *(list->items + i);
    }
    *(list->items + index) = value;
    list->size++;
}

void prepend(list *list, int value)
{
    insert(list, 0, value);
}

void check_address(void *p)
{
    if (p == NULL) {
        printf("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

int pop(list *list)
{
    if (list->size == 0) {
        printf("ERROR: List is empty\n");
        exit(EXIT_FAILURE);
    }

    int *item = list->items + list->size - 1;
    int ret = *(item);
    list->size--;

    if (list->size <= list->capacity / 4) {
        resize(list, list->capacity / 2);
    }

    return ret;
}

int delete(list *list, int index)
{
    if (list->size == 0) {
        printf("ERROR: List is empty\n");
        exit(EXIT_FAILURE);
    }
    if (index >= list->size) {
        printf("ERROR: Invalid index\n");
        exit(EXIT_FAILURE);
    }
    int ret;
    ret = *(list->items + index);

    int i;
    for (i = index + 1; i < list->size; i++) {
        *(list->items + i - 1) = *(list->items + i);
    }

    list->size--;
    if (list->size <= list->capacity / 4) {
        resize(list, list->capacity / 2);
    }
    return ret;
}

int my_remove(list *list, int item)
{
    int i;
    for (i = 0; i < list->size; i++) {
        if (*(list->items + i) == item) {
            return delete(list, i);
        }
    }
    return -1;
}

int find(list *list, int item)
{
    int i;
    for (i = 0; i < list->size; i++) {
        if (*(list->items + i) == item) {
            return i;
        }
    }
    return -1;
}

void print_debug(list *list)
{
    if (list->size == 0) {
        printf("List is empty\n");
        return;
    }
    printf("\nsize: %d\n", list->size);
    printf("capacity: %d\n", list->capacity);
    printf("address of first item: %p\n", list->items);
    printf("address of last item: %p\n", list->items + list->size - 1);

    int i;
    for (i = 0; i < list->size; i++) {
        if (i == 0) {
            printf("| ");
        }
        printf("%d | ", *(list->items + i));
    }
    printf("\n");
}
