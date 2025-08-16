#include <stdio.h>
#include <string.h>

int anagram(char* s) {
    int len = strlen(s);

    if (len % 2 != 0) {
        return -1;
    }

    int count1[26] = {0}, count2[26] = {0};
    int half = len / 2;

   
    for (int i = 0; i < half; i++) {
        count1[s[i] - 'a']++;
    }

   
    for (int i = half; i < len; i++) {
        count2[s[i] - 'a']++;
    }

   
    int changes = 0;
    for (int i = 0; i < 26; i++) {
        if (count1[i] > count2[i]) {
            changes += (count1[i] - count2[i]);
        }
    }

    return changes;
}

int main() {
    int num;
    scanf("%d", &num);  

    while (num--) {
        char s[10005]; 
        scanf("%s", s);

        int res = anagram(s);
        printf("%d\n", res);
    }

    return 0;
}
