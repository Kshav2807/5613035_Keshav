#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isPalindrome(char* s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}


int palindromeIndex(char* s) {
    int num = strlen(s);
    int i = 0, j = num - 1;

    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else {
            if (isPalindrome(s, i + 1, j)) return i;  
            if (isPalindrome(s, i, j - 1)) return j;  
            return -1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter no. of queries: ");
    scanf("%d", &n);

    while (n--) {
        char s[100005];
        printf("Enter string: ");
        scanf("%s", s);
        printf("Palindrome index: %d\n", palindromeIndex(s));
    }

    return 0;
}
