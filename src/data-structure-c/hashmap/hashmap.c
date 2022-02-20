#include "hashmap.h"

HashMap* create_new(int capacity)
{
    HashMap *new = (HashMap*)malloc(sizeof(HashMap));
    new->data = (Node**)malloc(sizeof(Node*) * capacity);

    // Define array of Node pointer
    // The pointer still points to NULL
    // Need to allocate memory for each Node
    // and memory for Item in the node
    int i;
    for (i = 0; i < capacity; ++i) {
        new->data[i] = NULL;
    }

    new->size = capacity;

    return new;
}

int hash(const char* key, const int m)
{
    int hash = 0;
    int i;
    for (i = 0; key[i] != '\0'; ++i) {
        /* printf("%d\n", key[i]); */
        hash = hash * 31 + key[i];
    }

    return abs(hash % m);
}

Node* get(const HashMap *map, const char *key)
{
    int j = hash(key, map->size);
    Node *curr = map->data[j];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void add(HashMap *map, const char *key, const Node* node)
{
    int j = hash(key, map->size);
    Node *curr = get(map, key);

    if (curr != NULL) {
        free(curr->value);
        curr->value = strdup(node->value);
        return;
    }

    // Add to the head of the LinkedList (bucket)
    curr = (Node*)malloc(sizeof(Node));
    curr->key = strdup(node->key);
    curr->value = strdup(node->value);
    curr->next = map->data[j];
    map->data[j] = curr;
}

Node* create_new_node(const char *key, const char *value)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->key = strdup(key);
    new->value = strdup(value);

    return new;
}

void print_debug(const HashMap *map)
{
    int i;
    printf("==============\n");
    for (i = 0; i < map->size; ++i) {
        printf("Bucket %d: ", i); 
        Node *curr = map->data[i];
        while (curr) {
            printf("(%s %s) -> ", curr->key, curr->value);
            curr = curr->next;
        }
        printf("None\n");
    }
    printf("==============\n");
}
