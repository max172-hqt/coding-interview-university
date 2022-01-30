#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;
typedef Node* NodePtr;

// Insert and delete:
// NodePtr *sPtr is the address of the list
// this is used to modify the list (call by reference)
void insert(NodePtr *sPtr, char value);
char delete(NodePtr *sPtr, char value);

int isEmpty(NodePtr sPtr);
void printList(NodePtr currentPtr);
void instruction(void);

int main(void)
{
    NodePtr startPtr = NULL;
    int choice;
    char item;

    instruction();

    scanf("%d", &choice);

    while (choice != 3) {
        switch (choice) {
            case 1:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert(&startPtr, item);
                printList(startPtr);
                break;
            case 2:
                printf("Enter a character to remove: ");
                scanf("\n%c", &item);
                char ret = delete(&startPtr, item);
                if (ret != '\0') {
                    printf("%c removed\n", ret);
                } else {
                    printf("No element removed\n");
                }
                printList(startPtr);
                break;
            default:
                printf("Invalid choice\n");
                instruction();
                break;
        }

        printf("? ");
        scanf("%d", &choice);
    }

    return 0;
}

void instruction(void)
{
    printf("Press 1 to insert\n");
    printf("Press 2 to remove\n");
    printf("Press 3 to exit\n");
}

void printList(NodePtr curr)
{
    while (curr != NULL) {
        printf("%c -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Pointer to sPtr
// Insert a new value in sorted order
void insert(NodePtr *sPtr, char value)
{ 
    NodePtr prev;
    NodePtr curr;
    NodePtr newNode;

    newNode = malloc(sizeof(Node));

    if (newNode != NULL) {
        prev = NULL;
        curr = *sPtr;

        newNode->data = value;
        newNode->next = *sPtr;

        // change the value of sPtr (newNode address)
        if (*sPtr == NULL) {
            // Empty list
            *sPtr = newNode;
        } else {
            while (curr != NULL && value > curr->data) {
                prev = curr;
                curr = curr->next;
            }

            if (prev == NULL) {
                newNode->next = *sPtr;
                *sPtr = newNode;
            } else {
                prev->next = newNode;
                newNode->next = curr;
            }
        }
    } else {
        printf("Cannot allocate memory\n");
    }
}

// Delete a list element
/* char delete(NodePtr *sPtr, char value) */
/* { */
/*     NodePtr curr; */
/*     NodePtr prev; */

/*     prev = NULL; */
/*     curr = *sPtr; */

/*     while (curr != NULL && curr->data != value) { */
/*         prev = curr; */
/*         curr = curr->next; */
/*     } */

/*     if (curr == NULL) { */
/*         return '\0'; */
/*     } else { */
/*         if (prev == NULL) { */
/*             *sPtr = curr->next; */
/*         } else { */
/*             prev->next = curr->next; */
/*         } */
/*         free(curr); */
/*         return value; */
/*     } */
/* } */

char delete(NodePtr *sPtr, char value)
{
    NodePtr temp;
    NodePtr prev;
    NodePtr curr;

    if (*sPtr == NULL) {
        return '\0';
    }

    if ((*sPtr)->data == value) {
        temp = *sPtr;
        *sPtr = (*sPtr)->next;
        free(temp);
        return value;
    } else {
        prev = *sPtr;
        curr = (*sPtr)->next;

        while (curr != NULL && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) { // Loop to the end of the list
            temp = curr;
            prev->next = curr->next;
            free(temp);
            return value;
        }

        return '\0';
    }
}
