#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* countMatches(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    int* result = malloc(queries_count * sizeof(int));
    for (int i = 0; i < queries_count; i++) {
        int count = 0;
        for (int j = 0; j < strings_count; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        result[i] = count;
    }
    *result_count = queries_count;
    return result;
}

int main() {
    int n, q;
    scanf("%d", &n);
    
   
    char** strings = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strings[i] = malloc(1001); 
        scanf("%s", strings[i]);
    }

    scanf("%d", &q);

   
    char** queries = malloc(q * sizeof(char*));
    for (int i = 0; i < q; i++) {
        queries[i] = malloc(1001);
        scanf("%s", queries[i]);
    }

    int result_count;
    int* result = countMatches(n, strings, q, queries, &result_count);

    // Print the result
    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

   
    for (int i = 0; i < n; i++) free(strings[i]);
    free(strings);
    for (int i = 0; i < q; i++) free(queries[i]);
    free(queries);
    free(result);

    return 0;
}
