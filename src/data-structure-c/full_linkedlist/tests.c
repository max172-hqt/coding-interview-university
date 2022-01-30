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

void testValueAt()
{
    LinkedList *list = createNew();
    assert(valueAt(list, 0) == '\0'); 
    pushFront(list, 11);
    pushBack(list, 12);
    pushFront(list, 13);
    pushBack(list, 14);
    /* printDebug(list); */

    assert(valueAt(list, 0) == 13);
    assert(valueAt(list, 1) == 11);
    assert(valueAt(list, 2) == 12);
    assert(valueAt(list, 3) == 14);
    /* assert(valueAt(list, 5) == '\0'); */
}

void testInsert()
{
    LinkedList *list = createNew();
    insert(list, 1, 10);
    insert(list, 0, 10);
    insert(list, 0, 11);

    /* printDebug(list); */

    assert(size(list) == 2);
    pushBack(list, 12);
    assert(size(list) == 3);
    insert(list, 2, 13);
    insert(list, 2, 14);
    insert(list, 4, 15);
    insert(list, 0, 1);

    assert(size(list) == 7);
    /* printDebug(list); */
}

void runTests()
{
    testPushFront();
    testPushBack();
    testPopFront();
    testPopBack();
    testFrontBack();
    testValueAt();
    testInsert();
}
