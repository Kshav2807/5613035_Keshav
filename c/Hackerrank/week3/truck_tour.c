#include <stdio.h>
#include <stdlib.h>

int truckTour(int petrolpumps_rows, int petrolpumps_columns, int** petrolpumps) {
    long long total = 0;
    long long tank = 0;
    int start = 0;

    for (int i = 0; i < petrolpumps_rows; i++) {
        long long fuel = petrolpumps[i][0];
        long long dist = petrolpumps[i][1];

        total += (fuel - dist);
        tank += (fuel - dist);

        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return (total >= 0) ? start : -1;
}

int main() {
    int num;
    scanf("%d", &num);

    int **petrolpumps = (int**)malloc(num * sizeof(int*));
    for (int i = 0; i < num; i++) {
        petrolpumps[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &petrolpumps[i][0], &petrolpumps[i][1]);
    }

    int res = truckTour(num, 2, petrolpumps);
    printf("%d\n", res);

    for (int i = 0; i < num; i++) {
        free(petrolpumps[i]);
    }
    free(petrolpumps);

    return 0;
}
