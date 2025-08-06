#include <stdio.h>
#include <stdlib.h>
int* countingSort(int arr_count, int* arr, int* res_count){
    *res_count = 100;
    int* freq = calloc(100, sizeof(int));
    for (int i = 0; i<arr_count; i++){
    freq[arr[i]]++;
    }
    return freq;
}
int main(){
    int num;
    printf("Enter no. of elements: ");
    scanf("%d",&num);
    int* arr = malloc(num * sizeof(int));
    printf("Enter %d space separated integers:\n", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    int res_count;;
    int* res = countingSort(num, arr, &res_count);

    printf("Freq array:\n");
    for (int i = 0; i < res_count; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(arr);
    free(res);
    return 0;
}