#include <stdio.h>

int towerBreakers(int num, int a) {
    if (a == 1) {
        return 2; 
    }
    if (num % 2 == 0) {
        return 2;
    }
    return 1; 
}

int main() {
    int t;
    scanf("%d", &t); // number of test cases

    for (int i = 0; i < t; i++) {
        int num, a;
        scanf("%d %d", &num, &a);
        printf("%d\n", towerBreakers(num, a));
    }

    return 0;
}
