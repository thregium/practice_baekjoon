#include <stdio.h>

/*
문제 : N^2 * N^2(2 <= N <= 6) 크기의 얼음판에서 다음 행동을 Q(Q <= 100)번 한 후의
얼음판의 얼음 합과 가장 큰 얼음덩이의 크기를 구한다.
격자를 2^L_i(0 <= L_i <= N) 단위로 나눈 후 각 단위를 90도 시계방향으로 회전시킨 다음 상하좌우로 2칸 이하에만 얼음이 남아있는
칸의 얼음 양을 1씩 줄인다.
얼음덩이의 크기는 상하좌우로 0이 아니며 인접한 얼음의 양의 합이며, 처음 주어지는 얼음의 양은 1000 이하다.

해결 방법 : 회전 연산은 비트마스킹을 통해 비교적 간단히 구현 가능하다.
L로 나눈 나머지를 새 배열에서의 위치로 계산해 놓는 방식이다.
그리고 다음 단계는 방향 배열을 적당히 사용하면 되고, 마지막 얼음덩이의 크기는 간단한 플러드필로 구할 수 있다.

주요 알고리즘 : 구현, 시뮬레이션, 비트마스킹, 플러드필
*/

int ice[64][64], tmp[80][80], vis[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int big(int a, int b) {
    return a > b ? a : b;
}

int isvalid(int n, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y] || ice[x][y] == 0) return 0;
    return 1;
}

int dfs(int n, int x, int y) {
    vis[x][y] = 1;
    int r = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(n, x + dxy[i][0], y + dxy[i][1])) r += dfs(n, x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    int n, q, l, c = 0, b = 0;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            scanf("%d", &ice[i][j]);
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &l);
        for (int j = 0; j < (1 << n); j++) {
            for (int k = 0; k < (1 << n); k++) {
                tmp[(j >> l << l) + (k & ((1 << l) - 1)) + 1][(k >> l << l) + (~j & ((1 << l) - 1)) + 1] = ice[j][k];
            }
        }
        for (int j = 1; j <= (1 << n); j++) {
            for (int k = 1; k <= (1 << n); k++) {
                c = 0;
                for (int d = 0; d < 4; d++) {
                    if (tmp[j + dxy[d][0]][k + dxy[d][1]]) c++;
                }
                ice[j - 1][k - 1] = tmp[j][k] - (c < 3);
                if (ice[j - 1][k - 1] < 0) ice[j - 1][k - 1] = 0;
            }
        }
    }
    c = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            c += ice[i][j];
            if (!vis[i][j] && ice[i][j] > 0) b = big(b, dfs(1 << n, i, j));
        }
    }
    printf("%d\n%d", c, b);
    return 0;
}