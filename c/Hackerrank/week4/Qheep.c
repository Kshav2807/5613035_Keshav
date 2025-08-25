#include <stdio.h>

#define MAXQ 100005

long long heap[MAXQ];
int size = 0;

void swap(long long *a, long long *b) {
    long long t = *a; *a = *b; *b = t;
}

void bubbleUp(int i) {
    while (i > 1 && heap[i] < heap[i/2]) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

void bubbleDown(int i) {
    int s = i, l = 2*i, r = 2*i+1;
    if (l <= size && heap[l] < heap[s]) s = l;
    if (r <= size && heap[r] < heap[s]) s = r;
    if (s != i) {
        swap(&heap[i], &heap[s]);
        bubbleDown(s);
    }
}

void insert(long long x) {
    heap[++size] = x;
    bubbleUp(size);
}

void removeVal(long long x) {
    for (int i = 1; i <= size; i++) {
        if (heap[i] == x) {
            heap[i] = heap[size--];
            bubbleDown(i);
            bubbleUp(i);
            break;
        }
    }
}

long long getMin() {
    return size > 0 ? heap[1] : -1;
}

int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int t;
        long long v;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%lld", &v);
            insert(v);
        } else if (t == 2) {
            scanf("%lld", &v);
            removeVal(v);
        } else {
            printf("%lld\n", getMin());
        }
    }
    return 0;
}
