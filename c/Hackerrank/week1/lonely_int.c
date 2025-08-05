#include <stdio.h>
#include <stdlib.h>
int lonelyInteger(int arr[], int size){
    int res = 0;
    for(int i = 0; i<size; i++){
        res ^= arr[i];
    }
    return res;
}
int main(){
    int num;
    printf("Enter no. of elements");
    scanf("%d", &num);
    int* arr = malloc(num * sizeof(int));
    printf("Enter %d space-separated integers:\n", num);
      for(int i = 0; i<num; i++){
        scanf("%d", &arr[i]);
      }
       int unique = lonelyInteger(arr, num);
    printf("The unique element is: %d\n", unique);
    free(arr);
    return 0;
}