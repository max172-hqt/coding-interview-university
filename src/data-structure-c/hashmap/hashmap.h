#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifndef HASHMAP_H
#define HASHMAP_H

struct node {
    char* key;
    char* value;
    struct node *next;
};

typedef struct node Node;

struct hashmap {
    Node **data; // Array of pointers to nodes
    int size;
};

typedef struct hashmap HashMap;

HashMap* create_new(int capacity);
Node* create_new_node(const char *key, const char *value);

// key: current key
// m: size of the table
int hash(const char* key, const int m);

// Change exist key if already exists
void add(HashMap *map, const char *key, const Node* node);

Node* get(const HashMap *map, const char *key);
void print_debug(const HashMap *map);

#endif
