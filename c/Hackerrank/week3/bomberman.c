#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** bomberMan(int n, int r, char** grid) {
    if (n == 1) return grid;

    int full = (n % 2 == 0);
    if (full) {
        char** filled = malloc(r * sizeof(char*));
        for (int i = 0; i < r; i++) {
            filled[i] = malloc((strlen(grid[i]) + 1) * sizeof(char));
            for (int j = 0; j < strlen(grid[i]); j++) filled[i][j] = 'O';
            filled[i][strlen(grid[i])] = '\0';
        }
        return filled;
    }

    int cycles = (n - 3) % 4 == 0 ? 1 : 2;
    char** state = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        state[i] = malloc((strlen(grid[i]) + 1) * sizeof(char));
        strcpy(state[i], grid[i]);
    }

    for (int c = 0; c < cycles; c++) {
        char** filled = malloc(r * sizeof(char*));
        for (int i = 0; i < r; i++) {
            filled[i] = malloc((strlen(grid[i]) + 1) * sizeof(char));
            for (int j = 0; j < strlen(grid[i]); j++) filled[i][j] = 'O';
            filled[i][strlen(grid[i])] = '\0';
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < strlen(grid[i]); j++) {
                if (state[i][j] == 'O') {
                    filled[i][j] = '.';
                    if (i > 0) filled[i-1][j] = '.';
                    if (i < r-1) filled[i+1][j] = '.';
                    if (j > 0) filled[i][j-1] = '.';
                    if (j < strlen(grid[i])-1) filled[i][j+1] = '.';
                }
            }
        }
        for (int i = 0; i < r; i++) free(state[i]);
        free(state);
        state = filled;
    }
    return state;
}

int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    char** grid = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        grid[i] = malloc((c + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }
    char** res = bomberMan(n, r, grid);
    for (int i = 0; i < r; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}
