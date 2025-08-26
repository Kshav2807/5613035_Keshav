#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

struct Node* insertNode(struct Node* root, int v) {
    if (!root) return newNode(v);
    if (v <= root->val) root->left = insertNode(root->left, v);
    else root->right = insertNode(root->right, v);
    return root;
}

struct Node* findLCA(struct Node* root, int a, int b) {
    while (root) {
        if (a < root->val && b < root->val) root = root->left;
        else if (a > root->val && b > root->val) root = root->right;
        else return root;
    }
    return NULL;
}

int main() {
    int num;
    scanf("%d", &num);

    struct Node* root = NULL;
    for (int i = 0; i < num; i++) {
        int x;
        scanf("%d", &x);
        root = insertNode(root, x);
    }

    int v1, v2;
    scanf("%d %d", &v1, &v2);

    struct Node* ans = findLCA(root, v1, v2);
    printf("%d\n", ans->val);

    return 0;
}
