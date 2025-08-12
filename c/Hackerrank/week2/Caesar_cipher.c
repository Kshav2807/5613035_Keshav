#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* caesarCipher(char* s, int a) {
    int len = strlen(s);
    char* res = malloc(len + 1);
    if (!res) return NULL;

    a = a % 26;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c >= 'a' && c <= 'z') {
            res[i] = ((c - 'a' + a) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            res[i] = ((c - 'A' + a) % 26) + 'A';
        } else {
            res[i] = c;
        }
    }
    res[len] = '\0';

    return res;
}

int main() {
    int num, p;
    scanf("%d", &num);
    char* s = malloc(num + 1);
    if (!s) {
        printf("Memory allocation failed\n");
        return 1;
    }

    scanf("%s", s);
    scanf("%d", &p);

    char* encrypted = caesarCipher(s, p);
    if (!encrypted) {
        printf("Memory allocation failed\n");
        free(s);
        return 1;
    }

    printf("%s\n", encrypted);

    free(s);
    free(encrypted);
    return 0;
}
