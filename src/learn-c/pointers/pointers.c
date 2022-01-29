#include <stdio.h>

int main(void) {
    int a;
    int* aPtr;

    a = 7;
    aPtr = &a;

    printf("Address %p\n", aPtr);
    printf("Address %p\n", &aPtr;
    printf("compl %p\n", *&aPtr);
    printf("Value %d\n", *aPtr);

    return 0;
}

