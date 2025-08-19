#include <stdio.h>
#include <stdlib.h>
void minimumBribes(int num, int* arr) {
    int total = 0;
    for (int indx = 0; indx < num; indx++) {
        if (arr[indx] - (indx + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }
        for (int k = (arr[indx] - 2 > 0 ? arr[indx] - 2 : 0); k < indx; k++) {
            if (arr[k] > arr[indx]) {
                total++;
            }
        }
    }
    printf("%d\n", total);
}

int main() {
    int a;
    scanf("%d", &a);
    while (a--) {
        int n;
        scanf("%d", &n);
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        minimumBribes(n, arr);
        free(arr);
    }
    return 0;
}
