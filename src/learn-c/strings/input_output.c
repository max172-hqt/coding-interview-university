#include <stdio.h>
#define SIZE 80

void reverse(const char * const sPtr);

int main(void)
{
    char sentence[SIZE];
    printf("Enter a line of text:\n");
    fgets(sentence, SIZE, stdin);
    printf("The line backward is:\n");
    reverse(sentence);
    return 0;
}

void reverse(const char * const sPtr) 
{
    if (sPtr[0] == '\0') {
        return;
    } else {
        reverse(&sPtr[1]);
        putchar(sPtr[0]);
    }
}
