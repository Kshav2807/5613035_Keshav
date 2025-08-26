#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10 

typedef struct Node {
    struct Node *next[SIZE];
    bool isEnd;
} Node;

Node* newNode() {
    Node *n = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < SIZE; i++) n->next[i] = NULL;
    n->isEnd = false;
    return n;
}

bool addWord(Node *root, char *word) {
    Node *cur = root;
    for (int i = 0; word[i]; i++) {
        int id = word[i] - 'a';
        if (!cur->next[id]) cur->next[id] = newNode();
        cur = cur->next[id];
        if (cur->isEnd) return false;
    }
    for (int j = 0; j < SIZE; j++) {
        if (cur->next[j]) return false; 
    }
    cur->isEnd = true;
    return true;
}

int main() {
    int num;
    scanf("%d", &num);

    Node *root = newNode();
    char word[105];

    for (int i = 0; i < num; i++) {
        scanf("%s", word);
        if (!addWord(root, word)) {
            printf("BAD SET\n%s\n", word);
            return 0;
        }
    }

    printf("GOOD SET\n");
    return 0;
}
