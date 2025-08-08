#include <stdio.h>
#include <stdlib.h>

int flippingMatrix(int matrix_rows, int matrix_columns, int **matrix) {
    int n = matrix_rows / 2; 
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = matrix[i][j];
            int b = matrix[i][matrix_columns - j - 1];
            int c = matrix[matrix_rows - i - 1][j];
            int d = matrix[matrix_rows - i - 1][matrix_columns - j - 1];

           
            int max1 = (a > b) ? a : b;
            int max2 = (c > d) ? c : d;
            int max_final = (max1 > max2) ? max1 : max2;

            sum += max_final;
        }
    }
    return sum;
}

int main() {
    int q;
    scanf("%d", &q);

    for (int t = 0; t < q; t++) {
        int n;
        scanf("%d", &n);

        int size = 2 * n;
        int **matrix = malloc(size * sizeof(int*));

        for (int i = 0; i < size; i++) {
            matrix[i] = malloc(size * sizeof(int));
            for (int j = 0; j < size; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int result = flippingMatrix(size, size, matrix);
        printf("%d\n", result);

     
        for (int i = 0; i < size; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }

    return 0;
}
