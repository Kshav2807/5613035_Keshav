#include <stdio.h>

long sumXor(long num) {
    if (num == 0) 
    return 1; 

    int zeroBits = 0;
    while (num > 0) {
        if ((num & 1) == 0) 
        zeroBits++; 
        num >>= 1; 
    }
    return 1L << zeroBits; 
}

int main() {
    long num;
    scanf("%ld", &num); 

    long res = sumXor(num);
    printf("%ld\n", res); 
    return 0;
}
