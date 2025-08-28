#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int cmpAsc(const void *a, const void *b) {
    return ((Pair*)a)->val - ((Pair*)b)->val;
}

int cmpDesc(const void *a, const void *b) {
    return ((Pair*)b)->val - ((Pair*)a)->val;
}

int countSwaps(int *arr, int num, int rev) {
    Pair *sorted = malloc(num * sizeof(Pair));
    for (int i = 0; i < num; i++) {
        sorted[i].val = arr[i];
        sorted[i].idx = i;
    }

    if (!rev) qsort(sorted, num, sizeof(Pair), cmpAsc);
    else qsort(sorted, num, sizeof(Pair), cmpDesc);

    int *visited = calloc(num, sizeof(int));
    int swaps = 0;

    for (int i = 0; i < num; i++) {
        if (visited[i] || sorted[i].idx == i) continue;

        int cycle = 0, j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = sorted[j].idx;
            cycle++;
        }
        if (cycle > 1) swaps += (cycle - 1);
    }

    free(visited);
    free(sorted);
    return swaps;
}

int lilysHomework(int *arr, int num) {
    int a = countSwaps(arr, num, 0);
    int b = countSwaps(arr, num, 1);
    return a < b ? a : b;
}

int main() {
    int num;
    scanf("%d", &num);
    int *arr = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) scanf("%d", &arr[i]);

    printf("%d\n", lilysHomework(arr, num));
    free(arr);
    return 0;
}
