#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAYS_H
#define ARRAYS_H

struct array_list {
    int *items;
    int capacity;
    int size;
};

typedef struct array_list list;

list* create_new(int capacity);
void push(list *list, int value);
void print_debug(list *list);

#endif
