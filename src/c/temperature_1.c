#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 5;

    for (celsius = lower; celsius <= upper; celsius += step) {
        fahr = 9.0 * (celsius + 32.0) / 5.0;
        printf("%3.f %6.1f\n", celsius, fahr);
    }
}
