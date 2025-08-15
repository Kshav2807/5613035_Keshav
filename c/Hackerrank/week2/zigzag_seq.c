#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    if (int_a < int_b) {
        return -1;
    } else if (int_a > int_b) {
        return 1;
    } else {
        return 0;
    }
}

void findZigZagSequence(int* a, int n) {
   qsort(a, n, sizeof(int), compare);
    int mid = (n - 1) / 2;
    int temp = a[mid];
    a[mid] = a[n - 1];
    a[n - 1] = temp;
    int start = mid + 1;
    int end = n - 2; // This was the crucial bugfix
    while (start < end) {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int* a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        findZigZagSequence(a, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        free(a);
    }
    return 0;
}
