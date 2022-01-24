#include <stdio.h>

void tryToModifyArray(const int b[]);

int main (void)
{
    int a[] = {10,20,30};
    tryToModifyArray(a);
    printf("%d %d %d\n", a[0], a[1], a[2]);
    return 0;
}

void tryToModifyArray(const int b[]) {
    // Error: Compile time error
    b[0] = 1;
    b[1] = 1;
    b[2] = 1;
}
