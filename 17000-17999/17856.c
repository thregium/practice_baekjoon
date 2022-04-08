#include <stdio.h>
#define INF 1012345678

/*
문제 : R * C(R, C <= 500) 크기의 지형에 대해 각 지형의 높이가 주어진다.
왼쪽 끝에서 오른쪽 끝까지 인접한 오른쪽 3 방향 중 하나로 이동 가능하고, pass(상하의 지형보다는 낮고,
좌우의 지형보다는 높은 곳)인 곳을 정확히 N(N <= 10)개 통과하는 경로가 있는 지 확인하고,
있는 경우 그 중 높이의 합이 최소인 곳을 구한다. -1인 곳은 지형이 아닌 곳이다.

해결 방법 : 다이나믹 프로그래밍을 통해 해결한다. pass인 곳을 먼저 확인해 놓은 다음,
각 좌표와 통과한 pass 수마다 높이의 합의 최솟값을 저장해 나간다. 초기 값은 무한대이고, 왼쪽부터 차례로
높이의 합을 갱신해 나간 다음 오른쪽 끝에서 최솟값을 확인해 무한대면 impossible을,
그 외에는 그 값을 출력하면 된다.

주요 알고리즘 : DP

출처 : ECNA 2019 E번
*/

int topo[512][512], ispass[512][512], mem[512][512][12];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int r, c, n, res = INF;
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &topo[i][j]);
        }
    }
    for (int i = 0; i <= r + 1; i++) {
        for (int j = 0; j <= c + 1; j++) {
            for (int k = 0; k <= n; k++) mem[i][j][k] = INF;
        }
    }
    for (int i = 2; i <= r - 1; i++) {
        for (int j = 2; j <= c - 1; j++) {
            if (topo[i][j - 1] < 0 || topo[i][j + 1] < 0) continue;
            if (topo[i][j - 1] < topo[i][j] && topo[i][j + 1] < topo[i][j] &&
                topo[i - 1][j] > topo[i][j] && topo[i + 1][j] > topo[i][j]) ispass[i][j] = 1;
            else ispass[i][j] = 0;
        }
    }
    for (int i = 1; i <= r; i++) {
        if (topo[i][1] >= 0) mem[i][1][0] = topo[i][1];
    }
    for (int i = 2; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            if (topo[j][i] < 0) continue;
            for (int k = 0; k <= n; k++) {
                if (ispass[j][i] && k == 0) continue;
                if (ispass[j][i]) {
                    for (int l = -1; l <= 1; l++) {
                        mem[j][i][k] = small(mem[j][i][k], mem[j + l][i - 1][k - 1] + topo[j][i]);
                    }
                }
                else {
                    for (int l = -1; l <= 1; l++) {
                        mem[j][i][k] = small(mem[j][i][k], mem[j + l][i - 1][k] + topo[j][i]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        res = small(res, mem[i][c][n]);
    }
    if (res == INF) printf("impossible");
    else printf("%d", res);
    return 0;
}