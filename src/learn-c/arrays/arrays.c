#include <stdio.h>
#define SIZE 5

void modifyArray(int b[], int size);
void modifyElement(int* e);

int main(void) 
{
    /* int n[10]; */
    /* int i; */

    /* for (i = 0; i < 10; i++) { */
    /*     n[i] = 0; */
    /* } */

    /* for (i = 0; i < 10; i++) { */
    /*     printf("%2d%10d\n", i, n[i]); */
    /* } */

    /* char string[] = "first"; */
    // Leave room for terminated char
    /* char string2[20]; */
    // Value of an array name is the address of first element
    // so we don't need & here
    /* scanf("%s", string2); */

    int a[SIZE] = {0,1,2,3,4};
    int i; // counter

    for (i = 0; i < SIZE; i++) {
        printf("%3d\n", a[i]);
    }

    modifyArray(a, SIZE);
    printf("After\n");

    for (i = 0; i < SIZE; i++) {
        printf("%3d\n", a[i]);
    }

    modifyElement(&a[3]);
    printf("Modify element\n");
    for (i = 0; i < SIZE; i++) {
        printf("%3d\n", a[i]);
    }
}

void modifyArray(int b[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        b[i] *= 2;
    }
}

void modifyElement(int* e) {
    *e *= 2;
}
