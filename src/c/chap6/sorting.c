#include <stdio.h>
#define SIZE 10

void insertionSort(int a[]);
void selectionSort(int a[]);
void bubbleSort(int a[]);
void swap(int* xp, int* yp);

int main (void)
{
    int a[SIZE] = {101, 100, 3, 4, 1, 5, 10, 7, 3};
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    bubbleSort(a);
    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}

void insertionSort(int a[]) 
{
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = i; j >= 0; j--) {
            if (a[j] < a[j-1]) {
                swap(&a[j], &a[j-1]);
            } else {
                break;
            }
        }
    }
}

void selectionSort(int a[]) 
{
    int i, j, minIdx;

    for (i = 0; i < SIZE; i++) {
        minIdx = i;
        for (j = i + 1; j < SIZE; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        swap(&a[minIdx], &a[i]);
    }
}

void bubbleSort(int a[]) 
{
    int i, j;
    for (i = 1; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void swap(int* xp, int* yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}
