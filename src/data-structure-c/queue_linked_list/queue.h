#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#ifndef QUEUE_H
#define QUEUE_H

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

struct linked_list {
    Node *head;
    Node *tail;
};

typedef struct linked_list Queue;

Queue* create_new();
// Add value at position at tail
void enqueue(Queue *queue, int value);
// Remove value at head
int dequeue(Queue *queue);
bool empty(Queue *queue);
void check_address(void *p);
void print_debug(Queue *queue);

#endif
