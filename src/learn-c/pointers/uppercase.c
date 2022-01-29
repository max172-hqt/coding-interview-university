#include <stdio.h>
#include <ctype.h>

void convertToUppercase(char* sPtr);

int main (void)
{
    char s[] = "lowercase and $23.33";

    printf("Original: %s\n", s);
    convertToUppercase(s);
    printf("Uppercase: %s\n", s);

    return 0;
}

void convertToUppercase(char* sPtr) 
{
    while (*sPtr != '\0') {
        if (islower(*sPtr)) {
            *sPtr = toupper(*sPtr);
        }
        sPtr++;
    }
}
