#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int arr[100000];   
    int top;
} Stack;


void init(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, int value) {
    s->arr[++(s->top)] = value;
}


int pop(Stack *s) {
    if (isEmpty(s)) return -1;
    return s->arr[(s->top)--];
}


int peek(Stack *s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}

int main() {
    int q;
    scanf("%d", &q);

    Stack input, output;
    init(&input);
    init(&output);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
         
            int value;
            scanf("%d", &value);
            push(&input, value);

        } else if (type == 2) {
          
            if (isEmpty(&output)) {
                while (!isEmpty(&input)) {
                    push(&output, pop(&input));
                }
            }
            pop(&output);

        } else if (type == 3) {
          
            if (isEmpty(&output)) {
                while (!isEmpty(&input)) {
                    push(&output, pop(&input));
                }
            }
            printf("%d\n", peek(&output));
        }
    }
    return 0;
}
