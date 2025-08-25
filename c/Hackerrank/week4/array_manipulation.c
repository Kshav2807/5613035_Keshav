#include <stdio.h>
#include <stdlib.h>

long arrayManipulation(int n, int m, int queries[][3]) {
    long* arr = calloc(n + 2, sizeof(long));
    for (int i = 0; i < m; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];
        arr[a] += k;
        arr[b + 1] -= k;
    }
    long max = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += arr[i];
        if (sum > max) max = sum;
    }
    free(arr);
    return max;
}

int main() {
    int num, m;
    scanf("%d %d", &num, &m);
    int queries[m][3];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }
    long res = arrayManipulation(num, m, queries);
    printf("%ld\n", res);
    return 0;
}
