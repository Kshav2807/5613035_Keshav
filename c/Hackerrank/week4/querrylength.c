#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int find_max(int *arr, int start, int k) {
    int m = arr[start];
    for (int i = 1; i < k; i++) {
        if (arr[start + i] > m) {
            m = arr[start + i];
        }
    }
    return m;
}

int* solve(int num, int *arr, int q, int *queries, int *result_count) {
    *result_count = q;
    int *res = malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        int k = queries[i];
        int min_of_max = find_max(arr, 0, k);
        for (int j = 1; j <= num - k; j++) {
            int current_max = find_max(arr, j, k);
            min_of_max = min(min_of_max, current_max);
        }
        res[i] = min_of_max;
    }
    return res;
}

int main() {
    int num, q;
    scanf("%d %d", &num, &q);
    int *arr = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    int *queries = malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d", &queries[i]);
    }
    int result_count;
    int *result = solve(num, arr, q, queries, &result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }
    free(arr);
    free(queries);
    free(result);
    return 0;
}
