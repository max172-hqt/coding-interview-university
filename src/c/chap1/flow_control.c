#include <stdio.h>
#include <math.h>

int main(void)
{
    /* int counter = 0; */

    /* while (++counter <= 10) { */
    /*     printf("%d\n", counter); */
    /* } */

    /* for (counter = 1; counter <= 10; counter++) { */
    /*     printf("%d\n", counter); */
    /* } */

    double principal = 1000.0;
    double rate = .05;
    double amount;
    int year;

    printf("%4s%21s\n", "year", "Amount on deposit");
    for (year = 1; year <= 10; year++) {
        amount = principal * pow(1 + rate, year);
        printf("%4d%21.2f\n", year, amount);
    }
    
    return 0;
}
