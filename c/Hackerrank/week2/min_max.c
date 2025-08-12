#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) {
    int p = *(int*)a;
    int q = *(int*)b;
    return p - q;
}

int maxMin(int x, int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int), cmpfunc);

    int min_unfairness = arr[arr_count - 1] - arr[0];

    for (int i = 0; i <= arr_count - x; i++) {
        int diff = arr[i + x - 1] - arr[i];
        if (diff < min_unfairness) {
            min_unfairness = diff;
        }
    }

    return min_unfairness;
}

int main() {
    int num, k;
    scanf("%d", &num);
    scanf("%d", &k);

    int* arr = malloc(num * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int res = maxMin(k, num, arr);
    printf("%d\n", res);

    free(arr);
    return 0;
}
