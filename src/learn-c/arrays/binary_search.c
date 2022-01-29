#include <stdio.h>
#define SIZE 10

int binarySearch(const int a[], int target, int low, int high);

int main(void)
{
    int a[SIZE] = {1,2,2,3,5,6,7,8,10,12};
    int target;

    printf("Enter an element\n");
    scanf("%d", &target);

    int result = binarySearch(a, target, 0, SIZE - 1);

    if (result != -1) {
        printf("Index of found element is %d\n", result);
    } else {
        printf("%d is not found\n", target);
    }

    return 0;
}

int binarySearch(const int a[], int target, int low, int high) 
{
    int middle;

    while (low <= high) {
        middle = (low + high) / 2;
        
        if (a[middle] == target) {
            return middle;
        } else if (target > a[middle]) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    return -1;
}

