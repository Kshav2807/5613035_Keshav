#include <stdio.h>
int main(){
    int num;
    scanf("%d\n", &num);
    int arr[num];
    int positive = 0, negative = 0, zero = 0;
    for (int i = 0; i<num; i++){
        scanf("%d\n", &arr[i]);
        if (arr[i] > 0)
        positive++;
    else if (arr[i] < 0)
         negative++;
        else 
        zero++;
    }
    printf("%.6f\n", (float)positive / num);
    printf("%.6f\n", (float)negative / num);
    printf("%.6f\n", (float)zero / num);
}