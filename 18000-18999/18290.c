#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 격자에 있는 각 칸에 절댓값 10000 이하의 수들이 적혀 있다.
K(K <- 4)개의 칸을 상하좌우로 인접하지 않게 선택할 때 그 칸들에 있는 수의 합의 최댓값을 구한다.

해결 방법 : K가 4 이하기 때문에 모든 칸을 선택하는 모든 경우를 시도해보면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : baekjoon
*/

int num[16][16], chk[16][16];
int dxy[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0} };
int best = -103000;

void track(int n, int m, int r, int c, int k, int s) {
    if (k == 0) {
        if (s > best) best = s;
        return;
    }
    for (int i = r; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == r && j < c) continue;
            if (chk[i][j]) continue;
            for (int d = 0; d < 5; d++) chk[i + dxy[d][0]][j + dxy[d][1]]++;
            track(n, m, i, j + 1, k - 1, s + num[i][j]);
            for (int d = 0; d < 5; d++) chk[i + dxy[d][0]][j + dxy[d][1]]--;
        }
    }
}

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    track(n, m, 1, 1, k, 0);
    printf("%d", best);
    return 0;
}