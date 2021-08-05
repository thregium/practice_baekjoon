#include <stdio.h>
#define MOD 1000000007

/*
문제 : N(N <= 2500)개의 정점이 있는 트리를 서로 인접한 정점끼리 다른 색으로 칠하며 정확히 K(K < N)개의 색상으로
칠하는 방법의 수를 구한다.

해결 방법 : 모든 리프노드에서 칠할 수 있는 노드의 개수를 생각하면, 해당 노드와 같은 색의 노드가 없었던 경우에는
K * f(n - 1, k - 1)가지 경우가 존재하고, 이미 있던 경우는 (K - 1) * f(n - 1, k)가지 경우가 존재한다.
따라서, 트리의 구조에 상관없이 해당 점화식에 따라 방법의 수를 구하면 된다.

주요 알고리즘 : DP

출처 : NCPC 2018 K번
*/

int mem[2560][2560];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    mem[1][1] = 1;
    //for (int i = 1; i <= k; i++) mem[1][i] = 1;
    //for (int i = 2; i <= n; i++) mem[i][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (long long j = 2; j <= k; j++) {
            if (i == 1 && j == 1) continue;
            mem[i][j] = (j * mem[i - 1][j - 1] + (j - 1) * mem[i - 1][j]) % MOD;
        }
    }
    printf("%d", mem[n][k]);
    return 0;
}