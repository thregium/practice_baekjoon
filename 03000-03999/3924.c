#include <stdio.h>

/*
문제 : N * N(3 <= N <= 7)의 칸에 높이 N의 페그가 있다. 두 명이서 검은색과 흰색 구슬을 번갈아가며
원하는 페그에 꽂는다. 꽂은 구슬은 페그의 구슬들 중 맨 윗자리에 오게 된다. 어떤 선으로든
M(3 <= M <= N)개의 같은 색인 구슬이 연속하면 그 색을 가진 사람이 이긴다고 할 때,
페그에 구슬을 꽂는 위치들이 P(P <= N^3)개 주어지면 이기는 사람의 번호와 그 사람이 가진 색을 구한다.
이기는 사람이 없다면 Draw를 출력한다. 구슬을 꽂는 과정에서 한 페그에 N개 넘게 꽂는 경우는 없다.
연속하는 선의 기준은 상하좌우전후, 6방향의 대각선, 4방향의 3차원 대각선이다.

해결 방법 : 먼저 가능한 모든 방향들에 대해 전처리를 통해 방향 배열을 만들어준다.
그리고 각 페그들을 스택으로 두고 구슬을 꽂아나간다. 구슬을 꽂을 때 마다 M개의 연속이 생겼는 지 확인하고,
생겼다면 그때 구슬을 꽂은 사람과 그때의 턴 번호를 출력하면 된다.
연속이 생겼는 지 여부는 각 지점에서 각 방향으로 이동하며 범위를 벗어나기 전까지 연속한 것이
M개 이상 있는 지 전부 확인하면 된다. N이 크지 않기 때문에 그렇게 하더라도 시간 초과가 일어나지 않는다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Ehime 2004 B번
*/

int peg[8][8][8];
int dxyz[26][3];

int isvalid(int n, int x, int y, int z) {
    if (x < 1 || y < 1 || z < 1 || x > n || y > n || z > n) return 0;
    else return 1;
}

int pegwin(int n, int m) {
    int cnt, x, y, z;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (peg[i][j][k] == 0) continue;
                for (int d = 0; d < 26; d++) {
                    cnt = 1;
                    for (int l = 1;; l++) {
                        x = i + dxyz[d][0] * l, y = j + dxyz[d][1] * l, z = k + dxyz[d][2] * l;
                        if (isvalid(n, x, y, z)) cnt++;
                        else break;
                        if (peg[x][y][z] != peg[i][j][k]) break;
                        if (cnt == m) {
                            return peg[i][j][k];
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(void) {
    int n, m, p = 0, x, y, r;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2004\\B\\tests\\01.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2004\\B\\tests\\01_t.out", "w", stdout);
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (i == 0 && j == 0 && k == 0) continue;
                dxyz[p][0] = i, dxyz[p][1] = j, dxyz[p][2] = k;
                p++;
            }
        }
    }

    while (1) {
        scanf("%d %d %d", &n, &m, &p);
        if (n == 0) break;
        r = 0;
        for (int i = 0; i < p; i++) {
            scanf("%d %d", &x, &y);
            if (r) continue;
            peg[x][y][++peg[x][y][0]] = (i & 1) + 1;
            r = pegwin(n, m);
            if (r == 1) printf("Black %d\n", i + 1);
            else if (r == 2) printf("White %d\n", i + 1);
        }
        if (r == 0) printf("Draw\n");

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k <= n; k++) peg[i][j][k] = 0;
            }
        }
    }
    return 0;
}