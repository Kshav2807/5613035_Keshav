#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int diagonalDiff(int num, int** arr){
    int pri = 0;
    int sec = 0;
    for (int i = 0; i<num; i++){
        pri += arr[i][i];
        sec += arr[i][num-1-i];
    }

    return abs(pri - sec);
}
int main (){
    int num;
    scanf("%d",&num);
    int ** arr = malloc(num* sizeof(int*));
     for (int i = 0; i < num; i++) {
        arr[i] = malloc(num * sizeof(int));
        for (int j = 0; j < num; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int res = diagonalDiff(num, arr);
    printf("%d\n", res);
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;


}
