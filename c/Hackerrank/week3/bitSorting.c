#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    char *x = *(char **)a;
    char *y = *(char **)b;
    int lx = strlen(x), ly = strlen(y);
    if (lx != ly) return lx - ly;
    return strcmp(x, y);
}

int main() {
    int num;
    scanf("%d", &num);
    char **arr = malloc(num * sizeof(char*));
    for (int i = 0; i < num; i++) {
        arr[i] = malloc(1000001);
        scanf("%s", arr[i]);
    }
    qsort(arr, num, sizeof(char*), cmp);
    for (int i = 0; i < num; i++) printf("%s\n", arr[i]);
    for (int i = 0; i < num; i++) free(arr[i]);
    free(arr);
    return 0;
}
