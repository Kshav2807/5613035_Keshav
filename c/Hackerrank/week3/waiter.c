#include <stdio.h>
#include <stdlib.h>

int* waiter(int number_count, int* number, int q, int* result_count) {
    int primes[q];
    int pcount = 0, num = 2;

    while (pcount < q) {
        int prime = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime) primes[pcount++] = num;
        num++;
    }

    int* A = (int*)malloc(number_count * sizeof(int));
    int topA = -1;
    for (int i = 0; i < number_count; i++) {
        A[++topA] = number[i];
    }

    int* result = (int*)malloc(number_count * sizeof(int));
    int r = 0;

    for (int i = 0; i < q; i++) {
        int* nextA = (int*)malloc(number_count * sizeof(int));
        int topNextA = -1;
        int* B = (int*)malloc(number_count * sizeof(int));
        int topB = -1;

        while (topA >= 0) {
            int plate = A[topA--];
            if (plate % primes[i] == 0) {
                B[++topB] = plate;
            } else {
                nextA[++topNextA] = plate;
            }
        }

        while (topB >= 0) {
            result[r++] = B[topB--];
        }

        free(A);
        A = nextA;
        topA = topNextA;
        free(B);
    }

    while (topA >= 0) {
        result[r++] = A[topA--];
    }

    free(A);
    *result_count = r;
    return result;
}

int main() {
    int num, q;
    scanf("%d %d", &num, &q);

    int* arr = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) scanf("%d", &arr[i]);

    int result_count;
    int* ans = waiter(num, arr, q, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", ans[i]);
    }

    free(arr);
    free(ans);
    return 0;
}
