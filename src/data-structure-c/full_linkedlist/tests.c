#include <stdio.h>
#include <assert.h>
#include "tests.h"
#include "linkedlist.h"

void testPushFront()
{
    LinkedList *list = createNew();
    assert(empty(list));
    pushFront(list, 10);
    assert(!empty(list));
    assert(size(list) == 1);
    pushFront(list, 11);
    pushFront(list, 12);
    assert(size(list) == 3);
    /* printDebug(list); */
}

void testPushBack()
{
    LinkedList *list = createNew();
    assert(empty(list));
    pushBack(list, 10);
    assert(!empty(list));
    assert(size(list) == 1);
    pushBack(list, 11);
    pushBack(list, 12);
    assert(size(list) == 3);
    pushFront(list, 13);
    assert(size(list) == 4);
    /* printDebug(list); */
}

void testPopFront()
{
    LinkedList *list = createNew();
    pushFront(list, 10);
    pushFront(list, 11);
    pushFront(list, 12);
    pushFront(list, 13);
    assert(size(list) == 4);

    assert(popFront(list) == 13);
    assert(size(list) == 3);

    assert(popFront(list) == 12);
    assert(size(list) == 2);

    assert(popFront(list) == 11);
    assert(size(list) == 1);

    assert(popFront(list) == 10);
    assert(size(list) == 0);

    assert(popFront(list) == '\0');
}

void testPopBack()
{
    LinkedList *list = createNew();
    assert(popBack(list) == '\0');
    pushFront(list, 10);
    assert(popBack(list) == 10);

    pushFront(list, 11);
    pushFront(list, 12);
    pushFront(list, 13);

    /* printDebug(list); */
    assert(popBack(list) == 11);
    /* printDebug(list); */
    assert(popFront(list) == 13);
    /* printDebug(list); */
    assert(popBack(list) == 12);
    /* printDebug(list); */

    // Re-add ok
    pushFront(list, 10);
    assert(size(list) == 1);
    /* printDebug(list); */
}

void testFrontBack()
{
    LinkedList *list = createNew();
    assert(front(list) == '\0');
    assert(back(list) == '\0');

    pushFront(list, 10);
    assert(front(list) == 10);
    assert(back(list) == 10);

    pushFront(list, 11);
    pushFront(list, 12);
    pushFront(list, 13);
    assert(front(list) == 13);
    assert(back(list) == 10);
}


void runTests()
{
    testPushFront();
    testPushBack();
    testPopFront();
    testPopBack();
    testFrontBack();
}
