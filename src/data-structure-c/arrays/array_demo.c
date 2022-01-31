#include <stdio.h>

int main(void)
{
    char *hello = "Hello world";

    printf("%s\n", hello);

    char *temp = hello;

    while (*temp != '\0') {
        printf("%c", *temp);
        temp++;
    }
    printf("\n");

    printf("%s\n", hello);

    int nums[5] = { 0,1,2,3,4 };
    int i;

    i = 0;
    while (i < 5) {
        printf("%d ", nums[i]);
        i++;
    }
    printf("\n");

    return 0;
}
