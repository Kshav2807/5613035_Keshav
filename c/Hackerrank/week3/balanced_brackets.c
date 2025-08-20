#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

char* isBalanced(char* s) {
    char stack[MAX];
    int top = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1 || !isMatching(stack[top--], s[i])) {
                return "NO";
            }
        }
    }
    return (top == -1) ? "YES" : "NO";
}

int main() {
    int p;
    scanf("%d", &p);
    while (p--) {
        char str[MAX];
        scanf("%s", str);
        printf("%s\n", isBalanced(str));
    }
    return 0;
}
