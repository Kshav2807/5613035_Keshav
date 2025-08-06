#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char* is_pangram(const char* str) {
    static char res_pangram[] = "pangram";
    static char res_not_pangram[] = "not pangram";
    
    int letters[26] = {0};
    int unique = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z') {
            int index = c - 'a';
            if (!letters[index]) {
                letters[index] = 1;
                unique++;
            }
        }
    }

    if (unique == 26)
        return res_pangram;
    else
        return res_not_pangram;
}

int main() {
    char input[1000];

    printf("Enter a sentence: \n");
    fgets(input, sizeof(input), stdin);
    
    
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    const char* res = is_pangram(input);
    printf("%s\n", res);

    return 0;
}
