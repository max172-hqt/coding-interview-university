#include "queue.h"

int main(void)
{
    Queue* queue = create_new();
    enqueue(queue, 10);
    enqueue(queue, 11);
    dequeue(queue);
    dequeue(queue);
    assert(empty(queue));
    /* dequeue(queue); */
    /* print_debug(queue); */
    return 0;
}
