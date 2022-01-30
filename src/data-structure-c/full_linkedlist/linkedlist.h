#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

struct linkedlist {
    Node *head;
    Node *tail;
};

typedef struct linkedlist LinkedList;

LinkedList* createNew();

void pushFront(LinkedList *list, int value);
void pushBack(LinkedList *list, int value);
int popFront(LinkedList *list);
int popBack(LinkedList *list);
int front(LinkedList *list);
int back(LinkedList *list);
int valueAt(LinkedList *list, int index);
void insert(LinkedList *list, int index, int value);
void erase(LinkedList *list, int index);
int nthFromEnd(LinkedList *list, int n);

int size(LinkedList *list);
bool empty(LinkedList *list);

void checkAddress(void *p);
void printDebug(LinkedList *list);
