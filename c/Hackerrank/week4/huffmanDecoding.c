#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;


Node* newNode(char data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}


void decode_huff(Node* root, char* s) {
    Node* curr = root;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') curr = curr->left;
        else curr = curr->right;


        if (!curr->left && !curr->right) {
            printf("%c", curr->data);
            curr = root;
        }
    }
    printf("\n");
}


int main() {

    Node* root = newNode('\0');
    root->left = newNode('\0');
    root->right = newNode('A');
    root->left->left = newNode('B');
    root->left->right = newNode('C');

    char encoded[] = "1001011";  
    decode_huff(root, encoded); 

    return 0;
}
