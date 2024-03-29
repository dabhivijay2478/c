#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius\tFahrenheit\n");
    for (celsius = upper; celsius >= lower; celsius = celsius - step) {
        fahr = (celsius * 9.0/5.0) + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
    }

    return 0;
}