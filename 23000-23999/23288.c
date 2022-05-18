#include <stdio.h>

/*
문제 : N * N(2 <= N <= 20) 크기의 땅에 자연수(<= 10)들이 쓰여 있다. 그리고 (1, 1) 지점에
1이 위, 3이 오른쪽에 오도록 주사위가 놓여 있다. 이때, 주사위를 설명에 따라 굴렸을 때 얻는 점수를 구한다.
1. 주사위를 이동 방향에 맞게 굴린다. 초기 이동 방향은 오른쪽이다. 움직일 수 없다면 반대로 굴린다.
2. 주사위가 놓인 곳의 수와 연결 요소를 이루는 같은 수들의 합을 점수에 추가한다.
3. 주사위의 밑면이 놓인 수보다 크다면 시계방향으로, 작다면 반시계방향으로 90도 이동 방향을 바꾼다.

해결 방법 : 각 과정을 시뮬레이션한다. 주사위의 눈은 하드코딩을 하는 것이 좋다.

주요 알고리즘 : 구현, 시뮬레이션, 플러드필

출처 : 삼성 SW 역량 테스트
*/

int a[32][32], vis[32][32], score[32][32];
const int dice[7][4] = { {0, 0, 0, 0}, {2, 4, 5, 3}, {1, 3, 6, 4}, {1, 5, 6, 2},
    {1, 2, 6, 5}, {1, 4, 6, 3}, {2, 3, 5, 4} };
const int rdice[7][7] = { {-1, -1, -1, -1, -1, -1, -1}, {-1, -1, 0, 3, 1, 2, -1}, {-1, 0, -1, 1, 3, -1, 2},
{-1, 0, 3, -1, -1, 1, 2}, {-1, 0, 1, -1, -1, 3, 2}, {-1, 0, -1, 3, 1, -1, 2}, {-1, -1, 0, 1, 3, 2, -1} };
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y, int sc) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || a[x][y] != sc) return 0;
    return 1;
}

int dfs(int x, int y, int sc) {
    int r = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], sc)) r += dfs(x + dxy[i][0], y + dxy[i][1], sc);
    }
    return r;
}

int main(void) {
    int k, x = 0, y = 0, dn = 6, rt = 3, mdir = 0, res = 0, ndn, nrt;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) vis[ii][jj] = 0;
            }
            score[i][j] = a[i][j] * dfs(i, j, a[i][j]);
        }
    }

    for (int i = 0; i < k; i++) {
        x += dxy[mdir][0];
        y += dxy[mdir][1];
        if (x < 0 || y < 0 || x >= n || y >= m) {
            mdir = ((mdir + 2) & 3);
            for (int j = 0; j < 2; j++) {
                x += dxy[mdir][0];
                y += dxy[mdir][1];
            }
        }
        ndn = dice[dn][(rdice[dn][rt] + mdir) & 3];
        nrt = dice[ndn][(rdice[ndn][dn] - mdir + 6) & 3];
        dn = ndn;
        rt = nrt;
        res += score[x][y];

        if (dn > a[x][y]) mdir = ((mdir + 1) & 3);
        else if (dn < a[x][y]) mdir = ((mdir + 3) & 3);
    }
    printf("%d", res);
    return 0;
}