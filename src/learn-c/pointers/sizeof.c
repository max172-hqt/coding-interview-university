#include <stdio.h>

size_t getSize(float *ptr);

int main(void)
{
    float array[20];
    printf("%zu\n", getSize(array));
    printf("%zu\n", sizeof(array));

    double real[20];
    printf("Numbe of elements %lu\n", sizeof(real) / sizeof(real[0]));

    return 0;
}

size_t getSize(float *ptr)
{
    return sizeof(ptr);
}
