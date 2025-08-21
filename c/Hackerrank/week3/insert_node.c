#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode* next;
} SinglyLinkedListNode;

typedef struct {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
} SinglyLinkedList;

SinglyLinkedListNode* create_node(int val) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));
    node->data = val;
    node->next = NULL;
    return node;
}

void insert_node(SinglyLinkedList** list, int val) {
    SinglyLinkedListNode* node = create_node(val);
    if (!(*list)->head) {
        (*list)->head = node;
    } else {
        (*list)->tail->next = node;
    }
    (*list)->tail = node;
}

void print_list(SinglyLinkedListNode* node) {
    while (node) {
        printf("%d", node->data);
        node = node->next;
        if (node) printf(" ");
    }
    printf("\n");
}

void free_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int val, int pos) {
    SinglyLinkedListNode* newNode = create_node(val);
    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }
    SinglyLinkedListNode* curr = head;
    for (int i = 0; i < pos - 1 && curr; i++) {
        curr = curr->next;
    }
    if (curr) {
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    SinglyLinkedList* list = malloc(sizeof(SinglyLinkedList));
    list->head = NULL;
    list->tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert_node(&list, val);
    }

    int data, pos;
    scanf("%d %d", &data, &pos);

    list->head = insertNodeAtPosition(list->head, data, pos);

    print_list(list->head);
    free_list(list->head);
    free(list);

    return 0;
}
