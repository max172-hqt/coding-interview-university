#include "queue.h"

int main(void)
{
    queue *q = create_new(5);
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    /* enqueue(q, 15); */
    print_debug(q);
    dequeue(q);
    print_debug(q);
    dequeue(q);
    print_debug(q);
    dequeue(q);
    print_debug(q);
    dequeue(q);
    print_debug(q);

    /* print_debug(q); */

    enqueue(q, 10);
    print_debug(q);
    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);

    print_debug(q);

    return 0;
}
