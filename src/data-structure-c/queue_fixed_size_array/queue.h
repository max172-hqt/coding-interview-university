#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

struct fixed_size_array_queue {
    int *data;
    int read;
    int write;
    int capacity;
};

typedef struct fixed_size_array_queue queue;

queue* create_new(int capacity);
void enqueue(queue *q, int value);
int dequeue(queue *q);
bool is_empty(queue *q);
bool full(queue *q);
void print_debug(queue *q);
void check_address(void *p);

#endif
