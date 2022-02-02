#include "queue.h"

queue* create_new(int capacity)
{
    queue* q = (queue*)malloc(sizeof(queue));
    check_address(q);
    q->read = 0;
    q->write = 0;
    // 1 block is unusable to differentiate read and write index
    q->data = (int*)malloc(sizeof(int) * (capacity + 1));
    q->capacity = capacity;

    return q;
}

void enqueue(queue *q, int value)
{
    if (full(q)) {
        printf("ERROR: Queue is full\n");
        exit(EXIT_FAILURE);
    }

    int positions = q->capacity + 1;
    *(q->data + q->write) = value;
    q->write = (q->write + 1) % positions;
}

int dequeue(queue *q)
{
    if (is_empty(q)) {
        printf("ERROR: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int positions = q->capacity + 1;
    int ret = *(q->data + q->read);
    q->read = (q->read + 1) % positions;
    return ret;
}

bool is_empty(queue *q)
{
    return q->write == q->read;
}

bool full(queue *q)
{
    int positions = q->capacity + 1;
    return q->read == (q->write + 1) % positions;
}

void print_debug(queue *q)
{
    printf("\nCapacity: %d\n", q->capacity);
    int positions = q->capacity + 1;

    int i;
    for (i = q->read; i != q->write; i = (i + 1) % positions) {
        printf("%d | ", *(q->data + i));
    }
    printf("\n");
}

void check_address(void *p)
{
    if (p == NULL) {
        printf("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
}
