#include <stdio.h>
#include <stdlib.h>

int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
    int* result = malloc(player_count * sizeof(int));
    int* unique = malloc(ranked_count * sizeof(int));
    int u = 0;
    for (int i = 0; i < ranked_count; i++) {
        if (i == 0 || ranked[i] != ranked[i - 1]) {
            unique[u++] = ranked[i];
        }
    }
    int pos = u - 1;
    for (int i = 0; i < player_count; i++) {
        while (pos >= 0 && player[i] >= unique[pos]) {
            pos--;
        }
        result[i] = pos + 2;
    }
    *result_count = player_count;
    free(unique);
    return result;
}

int main() {
    int ranked_count;
    scanf("%d", &ranked_count);
    int* ranked = malloc(ranked_count * sizeof(int));
    for (int i = 0; i < ranked_count; i++) scanf("%d", &ranked[i]);

    int player_count;
    scanf("%d", &player_count);
    int* player = malloc(player_count * sizeof(int));
    for (int i = 0; i < player_count; i++) scanf("%d", &player[i]);

    int result_count;
    int* result = climbingLeaderboard(ranked_count, ranked, player_count, player, &result_count);
    for (int i = 0; i < result_count; i++) printf("%d\n", result[i]);

    free(ranked);
    free(player);
    free(result);
    return 0;
}
