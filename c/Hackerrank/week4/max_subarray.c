#include <stdio.h>
#include <stdlib.h>

int* maxSubarray(int arr_count, int* arr, int* result_count) {
    *result_count = 2;
    int* result = malloc(2 * sizeof(int));

    int max_subarray = arr[0];
    int current_sum = arr[0];
    int max_subsequence = arr[0] > 0 ? arr[0] : 0;

    for (int i = 1; i < arr_count; i++) {
        current_sum = current_sum + arr[i] > arr[i] ? current_sum + arr[i] : arr[i];
        if (current_sum > max_subarray) max_subarray = current_sum;

        if (arr[i] > 0) {
            max_subsequence += arr[i];
        }
    }

    if (max_subsequence == 0) {
        max_subsequence = arr[0];
        for (int i = 1; i < arr_count; i++) {
            if (arr[i] > max_subsequence) max_subsequence = arr[i];
        }
    }

    result[0] = max_subarray;
    result[1] = max_subsequence;

    return result;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test = 0; test < t; test++) {
        int n;
        scanf("%d", &n);
        int* arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        int result_count;
        int* result = maxSubarray(n, arr, &result_count);

        for (int i = 0; i < result_count; i++) {
            printf("%d", result[i]);
            if (i != result_count - 1) printf(" ");
        }
        printf("\n");

        free(arr);
        free(result);
    }

    return 0;
}
