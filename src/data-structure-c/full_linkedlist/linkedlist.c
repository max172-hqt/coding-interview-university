#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList* createNew()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    checkAddress(list);

    list->head = NULL;
    list->tail = NULL;
    return list;
}

int size(LinkedList *list)
{
    int res = 0;
    Node *curr = list->head;

    while (curr != NULL) {
        res++;
        curr = curr->next;
    }
    return res;
}

bool empty(LinkedList *list)
{
    return list->head == NULL;
}

void pushFront(LinkedList *list, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    checkAddress(newNode);
    newNode->data = value;

    /* if (list->head == NULL) { */
    /*     list->head = newNode; */
    /*     list->tail = list->head; */
    /* } else { */
    /*     newNode->next = list->head; */
    /*     list->head = newNode; */
    /* } */

    newNode->next = list->head;
    list->head = newNode;

    if (list->tail == NULL) {
        list->tail = list->head;
    }
}

void pushBack(LinkedList *list, int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    checkAddress(newNode);
    newNode->data = value;
    newNode->next = NULL;

    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

int popFront(LinkedList *list) {
    if (list->head == NULL) {
        printf("The list is empty\n");
        return '\0';
    }

    Node* itemToRemove = list->head;
    int ret = itemToRemove->data;
    list->head = list->head->next;
    free(itemToRemove);

    // If last item is removed and list is empty
    if (list->head == NULL) {
        list->tail = NULL;
    }

    return ret;
}

void printDebug(LinkedList *list)
{
    printf("Head %p\n", list->head);
    printf("Tail %p\n", list->tail);
    Node* curr = list->head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void checkAddress(void *p) {
    if (p == NULL) {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}
