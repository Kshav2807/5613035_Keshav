#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* balancedSums(int n, int* nums) {
    static char ansYes[] = "YES";
    static char ansNo[] = "NO";

    long long sumAll = 0;
    for (int i = 0; i < n; i++) {
        sumAll += nums[i];
    }

    long long sumLeft = 0;
    for (int i = 0; i < n; i++) {
        long long sumRight = sumAll - sumLeft - nums[i];
        if (sumLeft == sumRight) {
            return ansYes;
        }
        sumLeft += nums[i];
    }
    return ansNo;
}

int main() {
    int p;
    scanf("%d", &p);

    while (p--) {
        int n;
        scanf("%d", &n);

        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        char* res = balancedSums(n, nums);
        printf("%s\n", res);

        free(nums);
    }

    return 0;
}
