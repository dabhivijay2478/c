#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
    unsigned int number = 0b110110101;  
    int n = 3;  

    unsigned int result = rightrot(number, n);

    printf("Original number: %u\n", number);
    printf("Result after rotating %d positions to the right: %u\n", n, result);

    return 0;
}

unsigned int rightrot(unsigned int x, int n) {
    int num_bits = sizeof(unsigned int) * 8;  
    n = n % num_bits;  

    return (x >> n) | (x << (num_bits - n));
}
