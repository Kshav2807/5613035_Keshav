#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* highestValuePalindrome(char* s, int num, int k) {
    char* res = malloc((num + 1) * sizeof(char));
    strcpy(res, s);

    int* changed = calloc(num, sizeof(int));
    int left = 0, right = num - 1;

    while (left < right) {
        if (res[left] != res[right]) {
            if (k <= 0) {
                free(changed);
                return "-1";
            }
            char maxc = (res[left] > res[right]) ? res[left] : res[right];
            res[left] = res[right] = maxc;
            changed[left] = changed[right] = 1;
            k--;
        }
        left++;
        right--;
    }

    left = 0;
    right = num - 1;
    while (left <= right && k > 0) {
        if (left == right) {
            if (res[left] != '9' && k > 0) {
                res[left] = '9';
                k--;
            }
        } else if (res[left] != '9') {
            if (changed[left] || changed[right]) {
                if (k >= 1) {
                    res[left] = res[right] = '9';
                    k--;
                }
            } else if (k >= 2) {
                res[left] = res[right] = '9';
                k -= 2;
            }
        }
        left++;
        right--;
    }

    free(changed);
    return res;
}

int main() {
    int num, k;
    scanf("%d %d", &num, &k);
    char s[100001];
    scanf("%s", s);

    char* result = highestValuePalindrome(s, num, k);
    printf("%s\n", result);

    if (result != s && result[0] != '-') free(result);

    return 0;
}
