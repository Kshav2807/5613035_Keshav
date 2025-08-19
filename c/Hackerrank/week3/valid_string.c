#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* isValid(char* s) {
    static char yes[] = "YES";
    static char no[] = "NO";
    int freq[26] = {0};
    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }
    int f1 = 0, f2 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) continue;
        if (f1 == 0) {
            f1 = freq[i];
            c1++;
        } else if (freq[i] == f1) {
            c1++;
        } else if (f2 == 0) {
            f2 = freq[i];
            c2++;
        } else if (freq[i] == f2) {
            c2++;
        } else {
            return no;
        }
    }
    if (f2 == 0) return yes;
    if ((c1 == 1 && (f1 - 1 == f2 || f1 - 1 == 0)) ||
        (c2 == 1 && (f2 - 1 == f1 || f2 - 1 == 0)))
        return yes;
    return no;
}

int main() {
    char s[100005];
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}
