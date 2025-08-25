#include <stdio.h>
#include <stdlib.h>

int equalStacks(int num1, int* stack1, int num2, int* stack2, int num3, int* stack3) {
    int height1 = 0, height2 = 0, height3 = 0;
    for (int i = 0; i < num1; i++) height1 += stack1[i];
    for (int i = 0; i < num2; i++) height2 += stack2[i];
    for (int i = 0; i < num3; i++) height3 += stack3[i];

    int top1 = 0, top2 = 0, top3 = 0;

    while (1) {
        if (top1 == num1 || top2 == num2 || top3 == num3)
            return 0;

        if (height1 == height2 && height2 == height3)
            return height1;

        if (height1 >= height2 && height1 >= height3)
            height1 -= stack1[top1++];
        else if (height2 >= height1 && height2 >= height3)
            height2 -= stack2[top2++];
        else
            height3 -= stack3[top3++];
    }
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int* stack1 = malloc(n1 * sizeof(int));
    int* stack2 = malloc(n2 * sizeof(int));
    int* stack3 = malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++) scanf("%d", &stack1[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &stack2[i]);
    for (int i = 0; i < n3; i++) scanf("%d", &stack3[i]);

    int result = equalStacks(n1, stack1, n2, stack2, n3, stack3);
    printf("%d\n", result);

    free(stack1);
    free(stack2);
    free(stack3);

    return 0;
}
