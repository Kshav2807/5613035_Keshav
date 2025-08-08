#include <stdio.h>
#include <string.h>

int main() {
    char x[101], y[101];
    scanf("%s", x);
    scanf("%s", y);

    int len = strlen(x);
    char res[101];

    for (int i = 0; i < len; i++) {
        res[i] = (x[i] == y[i]) ? '0' : '1';
    }
    res[len] = '\0';

    printf("%s\n", res);
    return 0;
}
