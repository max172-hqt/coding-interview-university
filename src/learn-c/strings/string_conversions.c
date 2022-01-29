#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    /* double d = 99.9; */
    /* d = atof("99.0"); */
    /* printf("%.3f\n", d); */

    const char *string = "51.2% are admitted";

    double d;
    char *stringPtr;
    printf("%p\n", stringPtr);

    d = strtod(string, &stringPtr);
    printf("%.2f\n%s\n", d, stringPtr);

    return 0;
}
