#include <stdio.h>

int gcd(int p, int q) {
    while (q != 0) {
        int temp = q;
        q = p % q;
        p = temp;
    }
    return p;
}


int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}


int getTotalX(int a_count, int* a, int b_count, int* b) {
  
    int l = a[0];
    for (int i = 1; i < a_count; i++) {
        l = lcm(l, a[i]);
    }

   
    int g = b[0];
    for (int i = 1; i < b_count; i++) {
        g = gcd(g, b[i]);
    }

   
    int count = 0;
    for (int x = l; x <= g; x += l) {
        if (g % x == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int num, m;

    printf("Enter no. of elements in array p and q: ");
    scanf("%d %d", &num, &m);

    int a[num], b[m];

    printf("Enter no. elements of array p: ");
    for (int i = 0; i < num; i++) scanf("%d", &a[i]);

    printf("Enter no. elements of array q: ");
    for (int j = 0; j < m; j++) scanf("%d", &b[j]);

    int res = getTotalX(num, a, m, b );
    printf("Total numbers between sets: %d\n", res);

    return 0;
}
