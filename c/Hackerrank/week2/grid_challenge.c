#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sortRow(char *row) {
    int length = strlen(row);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (row[i] > row[j]) {
                char temp = row[i];
                row[i] = row[j];
                row[j] = temp;
            }
        }
    }
}


char* gridChallenge(int num, char **grid) {
    static char yes[] = "YES";
    static char no[] = "NO";

   
    for (int i = 0; i < num; i++) {
        sortRow(grid[i]);
    }

    
    int cols = strlen(grid[0]);
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < num - 1; r++) {
            if (grid[r][c] > grid[r + 1][c]) {
                return no;
            }
        }
    }

    return yes;
}

int main() {
    int x;
    scanf("%d", &x);

    while (x--) {
        int num;
        scanf("%d", &num);

       
        char **grid = (char **)malloc(num * sizeof(char *));
        for (int i = 0; i < num; i++) {
            grid[i] = (char *)malloc(105 * sizeof(char)); 
            scanf("%s", grid[i]);
        }

        
        printf("%s\n", gridChallenge(num, grid));

        
        for (int i = 0; i < num; i++) {
            free(grid[i]);
        }
        free(grid);
    }

    return 0;
}
