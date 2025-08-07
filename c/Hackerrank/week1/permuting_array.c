#include <stdio.h>
#include <stdlib.h>
int compare_asc(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int compare_desc(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}
char* twoArray(int k, int num, int* x, int* y){
    static char yes[] = "YES";
    static char no[] = "NO";

    qsort(x, num, sizeof(int), compare_asc);
    qsort(y, num, sizeof(int), compare_desc);

    for(int i = 0; i< num; i++){
        if(x[i] +y[i]< k){
            return no;
        }
    }
    return yes ;
}
int main() {
    int z;
    scanf("%d", &z);

    for (int query = 0; query < z; query++) {
        int num, k;
        scanf("%d %d", &num, &k);

        int x[num], y[num];

        for (int i = 0; i < num; i++) {
            scanf("%d", &x[i]);
        }

        for (int i = 0; i < num; i++) {
            scanf("%d", &y[i]);
        }

        char* res = twoArray(k, num, x, y);
        printf("%s\n", res);
    }

    return 0;
}
