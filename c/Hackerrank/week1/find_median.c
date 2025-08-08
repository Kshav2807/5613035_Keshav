#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y) {
    return (*(int*)x - *(int*)y);
}

int findMedian(int arr_store, int* arr) {
    qsort(arr, arr_store, sizeof(int), compare);
    return arr[arr_store / 2];
}

int main() {
    int num;
    scanf("%d", &num);

    int arr[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", findMedian(num, arr));
    return 0;
}
