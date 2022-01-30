#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void instruction(void);
void createLinkedList();
void displayLinkedList();

Node *head;
void createLinkedList()
{
    Node *newNode;
    Node *temp;
    int data;

    newNode = (Node*) malloc(sizeof(Node));

    if (newNode != NULL) {
        printf("Enter new data into the linkedlist\n");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    } else {
        printf("Cannot create new node\n");
    }
}

void displayLinkedList()
{
    Node *curr;
    curr = head;

    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }

    printf("NULL\n");
}


int main(void)
{
    int choice;
    char ch;
    Node *head = NULL;

    instruction();

    scanf("%d", &choice);

    while (choice != 3) {
        switch (choice) {
            case 1:
                createLinkedList();
                break;
            case 2:
                displayLinkedList();
                break;
            default:
                printf("Invalid choice\n");
                instruction();
                break;
        }
        instruction();
        scanf("%d", &choice);
    }

    return 0;
}

void instruction()
{
    printf("\nEnter 1 to create linkedlist\n");
    printf("Enter 2 to display linkedlist\n");
    printf("Enter 3 to exit\n");
}
