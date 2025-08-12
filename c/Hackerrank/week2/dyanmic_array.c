#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

int* dynamicArray(int num, int queries_rows, int queries_columns, int** queries, int* res_count) {
    int** arr = malloc(num * sizeof(int*));
    int* sizes = calloc(num, sizeof(int));
    int* caps = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        caps[i] = 1;
        arr[i] = malloc(caps[i] * sizeof(int));
    }

    int lastAnswer = 0;
    int maxResults = queries_rows;
    int* answers = malloc(maxResults * sizeof(int));
    *res_count = 0;

    for (int i = 0; i < queries_rows; i++) {
        int qtype = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int idx = (x ^ lastAnswer) % num;

        if (qtype == 1) {
            if (sizes[idx] == caps[idx]) {
                caps[idx] *= 2;
                arr[idx] = realloc(arr[idx], caps[idx] * sizeof(int));
            }
            arr[idx][sizes[idx]] = y;
            sizes[idx]++;
        } else if (qtype == 2) {
            int pos = y % sizes[idx];
            lastAnswer = arr[idx][pos];
            answers[*result_count] = lastAnswer;
            (*res_count)++;
        }
    }

    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);
    free(sizes);
    free(caps);

    return answers;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    getchar();

    int** queries = malloc(q * sizeof(int*));
    for (int i = 0; i < q; i++) {
        queries[i] = malloc(3 * sizeof(int));
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
        getchar(); 
    }

    int res_count;
    int* res = dynamicArray(n, q, 3, queries, &res_count);

    for (int i = 0; i < res_count; i++) {
        printf("%d\n", res[i]);
    }

    free(res);
    for (int i = 0; i < q; i++) {
        free(queries[i]);
    }
    free(queries);

    return 0;
}
