#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(const int*)a;
    long long y = *(const int*)b;
    return (x > y) - (x < y);
}


int pairs(int k, int arr_count, int* arr) {
    int count = 0;

   
    qsort(arr, arr_count, sizeof(int), cmp);

    int i = 0, j = 1;
    while (j < arr_count) {
        long long diff = (long long)arr[j] - (long long)arr[i];
        if (diff == k) {
            count++;
            i++;
            j++;
        } else if (diff < k) {
            j++;
        } else {
            i++;
            if (i == j) j++;
        }
    }
    return count;
}

int main() {
    int num, k;
    scanf("%d %d", &num, &k);

    int *arr = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int res = pairs(k, num, arr);
    printf("%d\n", res);

    free(arr);
    return 0;
}
