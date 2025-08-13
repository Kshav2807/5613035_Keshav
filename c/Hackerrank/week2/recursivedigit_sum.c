#include <stdio.h>
#include <string.h>

int DigitRecursive(long n) {
    if (n < 10) {
        return (int)n;
    }
    long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return DigitRecursive(sum);
}

int superDigit(char* n, int k) {
    long sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        sum += n[i] - '0';
    }
    sum *= k; 
    return DigitRecursive(sum);
}

int main() {
    char n[100001];
    int k;

   
    scanf("%s %d", n, &k);

    int res = superDigit(n, k);
    printf("%d\n", res);

    return 0;
}
