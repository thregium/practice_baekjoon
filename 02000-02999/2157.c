#include <stdio.h>

/*
문제 : N(N <= 300)개의 도시 중 M(2 <= M <= N)개 이하를 번호 순서대로 이동하려고 한다. 그래프의 간선은 K(K <= 100000)개이고,
각 간선은 가중치(<= 10000)를 갖는다. 1번 정점에서 N번 정점으로 이동하며 가중치 합이 가장 큰 경우 가중치 합을 구한다.
도달 불가능한 경우는 주어지지 않는다. 각 간선은 자기 자신으로 이동할 수 없지면 같은 정점 쌍끼리 잇거나
역방향으로 가는 간선이 있을 수 있다.

해결 방법 : 도시와 이동한 도시 수를 변수로 두고 DP를 한다. 먼저 모든 값을 음수로 초기화한 다음, (1, 1)부터 DP를 시작하면 된다.
이전의 정점 가운데 간선이 있는 곳에서 현재 위치까지 도달하는 것을 찾고 가중치 합이 가장 크도록 구해나간다.
최종적으로 N번째 정점의 [2, M] 사이 값 가운데 가장 큰 것이 답이 된다.
간선을 받을 때 같은 정점 쌍이 있음에 유의한다.

주요 알고리즘 : DP, 그래프 이론
*/

int mem[384][384], ed[384][384];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, k, a, b, c, r = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (c > ed[a][b]) ed[a][b] = c;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            mem[i][j] = -1;
        }
    }
    mem[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = 1; l < i; l++) {
                if (mem[l][j - 1] < 0) continue;
                if (ed[l][i]) mem[i][j] = big(mem[i][j], mem[l][j - 1] + ed[l][i]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        r = big(r, mem[n][i]);
    }
    printf("%d", r);
    return 0;
}