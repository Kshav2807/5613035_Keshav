#include <stdio.h>
int sockMerchant(int num, int arr[]) {
    int count[101] = {0}; 
    int pairs = 0;

    
    for (int i = 0; i < num; i++) {
        count[arr[i]]++;
    }

    
    for (int i = 0; i < 101; i++) {
        pairs += count[i] / 2;
    }

    return pairs;
}

int main() {
    int num;
    printf("Enter no. of socks: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter sock colors: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int res = sockMerchant(num, arr);
    printf("Total pairs: %d\n", res);

    return 0;
}