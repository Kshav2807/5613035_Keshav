#include <stdio.h>

void minMaxSum(int arr_count, int* arr) {
    long total = 0;
    long min = arr[0];
    long max = arr[0];

    for (int i = 0; i < arr_count; i++) {
        total += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    long min_sum = total - max;
    long max_sum = total - min;

    printf("%ld %ld\n", min_sum, max_sum);
}

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    minMaxSum(5, arr);
    return 0;
}
