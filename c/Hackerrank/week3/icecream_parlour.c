#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);

    while (a--) {
        int d, e;
        scanf("%d", &d);
        scanf("%d", &e);

        int arr[e];
        for (int i = 0; i < e; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < e; i++) {
            for (int j = i + 1; j < e; j++) {
                if (arr[i] + arr[j] == d) {
                    printf("%d %d\n", i + 1, j + 1);
                    i = e;  
                    break;
                }
            }
        }
    }
    return 0;
}
