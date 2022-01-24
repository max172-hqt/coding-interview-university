#include <stdio.h>

int main(void)
{
    int current;
    int n = 0;
    double total = 0;
    double average;

    while (1) {
        scanf("%d", &current);
        if (current != 9999) {
            total += current;
            n++;
        } else {
            break;
        }
    }

    average = total / n;
    printf("Average of %d numbers is: %.2f\n", n, average);

    return 0;
} 
