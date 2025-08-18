#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode DoublyLinkedListNode;
typedef struct DoublyLinkedList DoublyLinkedList;

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};

struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
};

DoublyLinkedListNode* create_doubly_linked_list_node(int node_data) {
    DoublyLinkedListNode* node = malloc(sizeof(DoublyLinkedListNode));
    node->data = node_data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insert_node_into_doubly_linked_list(DoublyLinkedList** doubly_linked_list, int node_data) {
    DoublyLinkedListNode* node = create_doubly_linked_list_node(node_data);
    if (!(*doubly_linked_list)->head) {
        (*doubly_linked_list)->head = node;
    } else {
        (*doubly_linked_list)->tail->next = node;
        node->prev = (*doubly_linked_list)->tail;
    }
    (*doubly_linked_list)->tail = node;
}

void print_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        printf("%d", node->data);
        node = node->next;
        if (node) printf(" ");
    }
    printf("\n");
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* curr = llist;
    DoublyLinkedListNode* temp = NULL;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL) {
        llist = temp->prev;
    }
    return llist;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = malloc(sizeof(DoublyLinkedList));
        llist->head = NULL;
        llist->tail = NULL;

        int llist_count;
        scanf("%d", &llist_count);

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            scanf("%d", &llist_item);
            insert_node_into_doubly_linked_list(&llist, llist_item);
        }

        DoublyLinkedListNode* llist1 = reverse(llist->head);
        print_doubly_linked_list(llist1);
        free_doubly_linked_list(llist1);
    }
    return 0;
}
