#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 격자형 도로들에서 K개의 도로가 없다고 할 때
(0, 0)에서 (N, M)으로 최단거리로 이동하는 방법의 가짓수를 구한다.

해결 방법 : 각 시작점에서 오른쪽과 아래쪽으로 갈 수 있는 지 여부를 저장한 후
다이나믹 프로그래밍을 하면 된다.

주요 알고리즘 : DP
*/

int un[128][128][2];
long long mem[128][128];

int main(void) {
    int n, m, k, x1, y1, x2, y2;
    scanf("%d %d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 < x2) un[x1][y1][0] = 1;
        else if (x1 > x2) un[x2][y1][0] = 1;
        else if (y1 < y2) un[x1][y1][1] = 1;
        else if (y1 > y2) un[x1][y2][1] = 1;
        else return 1;
    }
    mem[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!un[i][j][1]) mem[i][j + 1] += mem[i][j];
            if (!un[i][j][0]) mem[i + 1][j] += mem[i][j];
        }
    }
    printf("%lld", mem[n][m]);
    return 0;
}