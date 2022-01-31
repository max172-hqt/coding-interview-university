#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList* createNew()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    checkAddress(list);

    list->head = 0;
    list->tail = 0;
    return list;
}

int size(LinkedList *list)
{
    int res = 0;
    Node *curr = list->head;

    while (curr != 0) {
        res++;
        curr = curr->next;
    }
    return res;
}

bool empty(LinkedList *list)
{
    return list->head == 0;
}

void pushFront(LinkedList *list, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    checkAddress(newNode);
    newNode->data = value;

    /* if (list->head == 0) { */
    /*     list->head = newNode; */
    /*     list->tail = list->head; */
    /* } else { */
    /*     newNode->next = list->head; */
    /*     list->head = newNode; */
    /* } */

    newNode->next = list->head;
    list->head = newNode;

    if (list->tail == 0) {
        list->tail = list->head;
    }
}

void pushBack(LinkedList *list, int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    checkAddress(newNode);
    newNode->data = value;
    newNode->next = 0;

    if (list->tail == 0) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

int popFront(LinkedList *list) {
    if (list->head == 0) {
        return '\0';
    }

    Node* itemToRemove = list->head;
    int ret = itemToRemove->data;
    list->head = list->head->next;
    free(itemToRemove);

    // If last item is removed and list is empty
    if (list->head == 0) {
        list->tail = 0;
    }

    return ret;
}

int popBack(LinkedList *list)
{
    if (list->tail == 0) {
        return '\0';
    }

    Node *prev = 0;
    Node *curr = list->head;
    Node *itemToRemove;
    int ret;

    while (curr->next != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == 0) { // one item
        itemToRemove = list->head;
        list->head = 0;
        list->tail = 0;
    } else {
        itemToRemove = list->tail;
        prev->next = 0;
        list->tail = prev;
    }

    ret = itemToRemove->data;
    free(itemToRemove);
    return ret;
}

int front(LinkedList* list)
{
    if (list->head == 0) {
        return '\0';
    }
    return list->head->data;
}

int back(LinkedList* list)
{
    if (list->tail == 0) {
        return '\0';
    }
    return list->tail->data;
}

int valueAt(LinkedList *list, int index)
{
    if (list->head == 0) {
        printf("List is empty\n");
        return '\0';
    }

    Node *curr = list->head;    

    while (curr != 0 && index > 0) {
        index--;
        curr = curr->next;
    }

    if (index != 0) {
        printf("Out of bound!\n");
        return '\0';
    }

    return curr->data;
}

void insert(LinkedList *list, int index, int value)
{
    Node *curr;
    Node *prev;
    Node *newNode;

    prev = 0;
    curr = list->head;

    while (curr && curr->next != 0 && index > 0) {
        index--;
        prev = curr;
        curr = curr->next;
    }
    
    // 1 -> 2 -> 3 -> 4 -> 5
    // 1 -> 2 -> 3 -> 4 -> new -> 5
    if (index > 0) {
        printf("Index out of bounds\n");
        return;
    }

    newNode = (Node*)malloc(sizeof(Node));
    checkAddress(newNode);
    newNode->data = value;
    if (prev == 0) {
        // insert to head
        newNode->next = list->head;
        list->head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = curr;
    }

    if (list->tail == 0) {
        // empty list
        list->tail = list->head;
    }
}

void erase(LinkedList* list, int index)
{
    Node *prev;
    Node *curr;
    Node *itemToRemove;

    prev = 0;
    curr = list->head;

    while (curr && curr->next != NULL && index > 0) {
        index--;
        prev = curr;
        curr = curr->next;
    }

    if (index > 0) {
        printf("Index out of bounds\n");
        return;
    }

    if (curr == 0) {
        printf("List is empty\n");
    } else if (prev == 0) {
        itemToRemove = list->head;
        list->head = list->head->next;
        if (list->head == 0) {
            list->tail = 0;
        }
        free(itemToRemove);
    } else {
        itemToRemove = curr;
        prev->next = curr->next;

        if (prev->next == 0) {
            list->tail = prev;
        }
        free(itemToRemove);
    }
}

int nthFromEnd(LinkedList *list, int n)
{
    Node *fast;
    Node *slow;
    int current = 0;

    fast = list->head;
    slow = list->head;

    while (current < n && fast != 0 && fast->next != 0) {
        fast = fast->next; 
        current++;
    }

    if (current < n) { // fast becomes null
        printf("Index out of bounds\n");
        return '\0';
    }

    while (fast != 0 && fast->next != 0) {
        fast = fast->next;
        slow = slow->next;
    }

    if (slow != 0) {
        return slow->data;
    }

    return '\0';
}

void reverse(LinkedList *list)
{
    if (list->head == 0) {
        return;
    }

    Node *curr;
    Node *prev;
    Node *next;
    Node *newTail;

    curr = list->head;
    prev = 0;
    newTail = 0;
    // 1 -> 2 -> 3 -> 4 -> 5
    while (curr != 0) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        if (prev != 0 && newTail == 0) {
            newTail = prev;
        }
    }

    list->head = prev;
    list->tail = newTail;
}

int removeValue(LinkedList *list, int value)
{
    // empty list => return null
    //
    // 2 pointers, prev and curr
    // loop through the list
    // curr && curr->data != value
    // curr == null return -> no element will be found
    // otherwise curr will be the item to be removed
    // also need to consider updating the head and tail
    //
    // free the pointer
    // return value
    //
    if (list->head == 0) {
        return '\0';
    }

    Node *curr;
    Node *prev;
    Node *itemToRemove;

    if (list->head->data == value) {
        itemToRemove = list->head;
        list->head = list->head->next;
        free(itemToRemove);

        if (list->head == 0) {
            list->tail = 0;
        }

        return value;
    }

    curr = list->head->next;
    prev = list->head;

    while (curr != 0 && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != 0) { // curr is the item to be removed
        itemToRemove = curr;
        prev->next = curr->next;

        // what if tail is removed?
        if (prev->next == 0) {
            list->tail = prev;
        }
        free(itemToRemove);
        return value;
    }

    return '\0';
}

void printDebug(LinkedList *list)
{
    printf("Head %p\n", list->head);
    printf("Tail %p\n", list->tail);
    Node* curr = list->head;
    while (curr != 0) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n\n");
}

void checkAddress(void *p) {
    if (p == NULL) {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}
