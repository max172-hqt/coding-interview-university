#include "queue.h"

Queue* create_new()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    check_address(queue);
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void enqueue(Queue *queue, int value)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = value;
    if (queue->tail == 0) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

int dequeue(Queue *queue)
{
    Node *temp;
    int ret;
    if (queue->head == 0) {
        printf("ERROR: Queue is empty\n");
        exit(EXIT_FAILURE);
    } else {
        temp = queue->head;
        ret = temp->data;
        queue->head = queue->head->next;
        if (queue->head == 0) {
            queue->tail = 0;
        }
        free(temp);
        return ret;
    }
}

bool empty(Queue *queue)
{
    return queue->head == 0;
}

void check_address(void *p)
{
    if (p == NULL) {
        exit(EXIT_FAILURE);
    }
}

void print_debug(Queue *queue)
{
    printf("\nHead address: %p\n", queue->head);
    printf("Tail address: %p\n", queue->tail);
    Node* curr = queue->head;

    printf("Head to Tail\n");
    printf("HEAD -> ");
    while (curr != 0) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("END\n");
}
