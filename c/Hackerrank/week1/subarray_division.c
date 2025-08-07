#include <stdio.h>
int birthday(int a[], int num, int d, int m){
    int ways = 0;
    for(int i = 0; i<=num - m; i++){
        int sum = 0;

        for(int j = 0; j< m; j++){
         sum += a[i+j];
    }
    if(sum == d){
        ways++;
    }
}
 return ways;
}
int main() {
    int num;
    scanf("%d", &num);

    int a[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }

    int d, m;
    scanf("%d %d", &d, &m);

    int res = birthday(a, num, d, m);
    printf("%d\n", res);

    return 0;
}