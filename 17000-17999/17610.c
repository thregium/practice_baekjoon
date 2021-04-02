#include <stdio.h>
#include <stdlib.h>

int g[16], mem[16][5242880];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int k, s = 0, r = 0;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &g[i]);
        s += g[i];
    }
    qsort(g + 1, k, sizeof(int), cmp1);
    mem[0][s] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= s * 2; j++) {
            if (mem[i - 1][j]) {
                mem[i][j] = 1;
            }
            if (j >= g[i] && mem[i - 1][j - g[i]]) {
                mem[i][j] = 1;
            }
            if (j <= s * 2 - g[i] && mem[i - 1][j + g[i]]) {
                mem[i][j] = 1;
            }
        }
    }

    for (int i = s + 1; i <= s * 2; i++) {
        r += !mem[k][i];
        //if(mem[k][i]) printf("%d ", i - s);
    }
    printf("%d", r);
    return 0;
}