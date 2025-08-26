#include <stdio.h>
#include <stdlib.h>

int cmpAscending(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int hackerlandRadioTransmitters(int n, int *arr, int k) {
    if (n == 0) return 0;

    qsort(arr, n, sizeof(int), cmpAscending);

    int transmitters = 0;
    int idx = 0;

    while (idx < n) {
        transmitters++;
        int base = arr[idx];
        while (idx < n && arr[idx] <= base + k) {
            idx++;
        }
        int placedAt = arr[idx - 1];
        while (idx < n && arr[idx] <= placedAt + k) {
            idx++;
        }
    }

    return transmitters;
}

int main() {
    int num, k;
    scanf("%d %d", &num, &k);

    int *houses = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d", &houses[i]);
    }

    int res = hackerlandRadioTransmitters(num, houses, k);
    printf("%d\n", res);

    free(houses);
    return 0;
}
