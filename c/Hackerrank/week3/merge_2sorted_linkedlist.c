#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = x;
    p->next = NULL;
    return p;
}

Node* insertEnd(Node* head, int x) {
    Node* p = createNode(x);
    if (!head) return p;
    Node* q = head;
    while (q->next) q = q->next;
    q->next = p;
    return head;
}

Node* mergeSorted(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* head = NULL;
    Node* tail = NULL;

    if (a->val <= b->val) {
        head = a; 
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }
    tail = head;

    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a) ? a : b;

    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, x;
        Node* l1 = NULL;
        Node* l2 = NULL;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            l1 = insertEnd(l1, x);
        }

        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &x);
            l2 = insertEnd(l2, x);
        }

        Node* res = mergeSorted(l1, l2);
        printList(res);
    }
    return 0;
}
