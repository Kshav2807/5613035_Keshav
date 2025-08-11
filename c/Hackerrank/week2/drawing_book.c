#include <stdio.h>

int pageCount(int num, int a) {
    int fromFront = a / 2;                  // Turns from the front
    int fromBack = (num / 2) - (a / 2);       // Turns from the back
    return (fromFront < fromBack) ? fromFront : fromBack;
}

int main() {
    int num, a;

    printf("Enter total no. of pages: ");
    scanf("%d", &num);

    printf("Enter page no. to turn to: ");
    scanf("%d", &a);

    int res = pageCount(num, a);
    printf("Minimum page turns: %d\n", res);

    return 0;
}
