#include <stdio.h>

int maximum(int x, int y, int z);

int main(void) {
    int x, y, z;
    printf("Enter 3 numbers:\n");
    scanf("%d%d%d", &x, &y, &z);

    printf("Maximum is: %d\n", maximum(x, y, z));
    return 0;
}

int maximum(int x, int y, int z) {
    int max = x;

    if (y > max) {
        max = y;
    }

    if (z > max) {
        max = z;
    }

    return max;
}
