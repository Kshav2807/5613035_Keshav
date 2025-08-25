#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int cookies(int k, int n, int* A) {
    int ops = 0;

    while (1) {
        qsort(A, n, sizeof(int), cmp);

        if (A[0] >= k) return ops;
        if (n < 2) return -1;

        int newCookie = A[0] + 2 * A[1];

        A[1] = newCookie;
        for (int i = 0; i < n - 1; i++) A[i] = A[i + 1];
        n--;
        ops++;
    }
}

int main() {
    int num, k;
    scanf("%d %d", &num, &k);
    int* A = malloc(num * sizeof(int));

    for (int i = 0; i < num; i++) scanf("%d", &A[i]);

    int result = cookies(k, num, A);
    printf("%d\n", result);

    free(A);
    return 0;
}
