#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000

typedef struct {
    int type;    
    char *data;  
} Operation;

char *text;         
int text_len = 0;   
Operation stack[1000000]; 
int top = -1;

void push(int type, const char *data) {
    stack[++top].type = type;
    stack[top].data = data ? strdup(data) : NULL;
}

Operation pop() {
    return stack[top--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    text = (char *)malloc((MAX_LEN + 5) * sizeof(char));
    text[0] = '\0';

    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) { 
            char w[1000005];
            scanf("%s", w);
            int wlen = strlen(w);

            memcpy(text + text_len, w, wlen + 1);
            text_len += wlen;

            char buf[20];
            sprintf(buf, "%d", wlen);
            push(1, buf);

        } else if (type == 2) { 
            int k;
            scanf("%d", &k);

            int start = text_len - k;
            char *deleted = (char *)malloc((k + 1) * sizeof(char));
            memcpy(deleted, text + start, k);
            deleted[k] = '\0';

            text_len -= k;
            text[text_len] = '\0';

            push(2, deleted);
            free(deleted);

        } else if (type == 3) { 
            int k;
            scanf("%d", &k);
            printf("%c\n", text[k - 1]);

        } else if (type == 4) { 
            Operation last = pop();

            if (last.type == 1) {
                int len = atoi(last.data);
                text_len -= len;
                text[text_len] = '\0';
            } else if (last.type == 2) {
                int dlen = strlen(last.data);
                memcpy(text + text_len, last.data, dlen + 1);
                text_len += dlen;
            }
            free(last.data);
        }
    }

    free(text);
    return 0;
}
