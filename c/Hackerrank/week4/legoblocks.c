#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int legoBlocks(int num, int m) {
    long long* row = malloc((m + 1) * sizeof(long long));
    long long* solid = malloc((m + 1) * sizeof(long long));

    row[0] = 1;
    for (int w = 1; w <= m; w++) {
        row[w] = 0;
        for (int k = 1; k <= 4; k++) {
            if (w - k >= 0)
                row[w] = (row[w] + row[w - k]) % MOD;
        }
    }

    long long* total = malloc((m + 1) * sizeof(long long));
    for (int w = 1; w <= m; w++) {
        long long t = 1;
        for (int i = 0; i < num; i++) {
            t = (t * row[w]) % MOD;
        }
        total[w] = t;
    }

    solid[0] = 0;
    for (int w = 1; w <= m; w++) {
        long long bad = 0;
        for (int k = 1; k < w; k++) {
            bad = (bad + (solid[k] * total[w - k]) % MOD) % MOD;
        }
        solid[w] = (total[w] - bad + MOD) % MOD;  
    }

    int result = solid[m];
    free(row);
    free(total);
    free(solid);
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int num, m;
        scanf("%d %d", &num, &m);
        printf("%d\n", legoBlocks(num, m));
    }
    return 0;
}
