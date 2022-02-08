#include <stdio.h>
#include <stdlib.h>

#ifndef HASHMAP_H
#define HASHMAP_H

#define SIZE 10

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

struct hashmap {
    // Array of pointers to Node (Array of linkedlist)
    Node **data;
};

typedef struct hashmap HashMap;

#endif
