#include <stdio.h>
#define INF 1012345678

int coin[512][2], mem[10240];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int t, e, f, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &e, &f);
        f -= e;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &coin[i][0], &coin[i][1]);
        }

        for (int i = 1; i <= f; i++) mem[i] = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = coin[i][1]; j <= f; j++) {
                mem[j] = small(mem[j], mem[j - coin[i][1]] + coin[i][0]);
            }
        }

        if (mem[f] == INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", mem[f]);
    }
    return 0;
}