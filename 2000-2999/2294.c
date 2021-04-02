#include <stdio.h>
#include <stdlib.h>
#define INF 1234567890

int c[128], mem[128][10240];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) mem[0][i] = INF;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmp1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            mem[i][j] = small(mem[i - 1][j], c[i] > j ? INF : mem[i][j - c[i]] + 1);
        }
    }
    printf("%d", mem[n][k] == INF ? -1 : mem[n][k]);
    return 0;
}