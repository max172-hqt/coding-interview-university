#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct array_list {
    int *items;
    int capacity;
    int size;
};

typedef struct array_list list;

list* create_new(int capacity);
void push(list *list, int value);
void print_debug(list *list);
int size(list *list);
int capacity(list *list);
bool is_empty(list *list);
int at(list *list, int index);
void resize(list *list, int capacity);
void check_address(void *p);
void insert(list *list, int index, int value);
void prepend(list *list, int value);
int pop(list *list);
int delete(list *list, int index);
int my_remove(list *list, int item);
int find(list* list, int item);

#endif
