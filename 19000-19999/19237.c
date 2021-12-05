#include <stdio.h>

/*
문제 : N * N(N <= 20) 크기의 공간에 M(M <= 400)마리의 상어들이 있다. 상어들은 각 칸에 도착할 때 마다 K(K <= 1000)초동안
지속되는 냄새를 뿌린다. 각 상어들은 매 초마다 주변 칸들 가운데 냄새가 없는 칸, 없다면 자신의 냄새가 있는 칸으로 이동한다.
이동할 칸이 여럿인 경우 그 초에 보고 있던 방향의 우선순위를 따른다. 상어가 한 칸에 여러 마리가 도착하면
가장 번호가 작은 상어 외에는 전부 쫓겨난다고 할 때, 상어가 1마리만 남게 될 때 까지 걸리는 시간을 구한다.
1000초 이상인 경우 -1을 출력한다.

해결 방법 : 문제에 주어진대로 구현한다. 상어가 나가는 경우의 연산에 유의한다.

주요 알고리즘 : 구현, 시뮬레이션
*/

typedef struct shark {
    int x, y; //좌표
    int d, n; //방향, 번호
    int pri[5][5]; //우선순위(방향별)
} shark;

int space[32][32], stmp[32][32]; //냄새(번호 * 65536 + 시각), 임시 배열
const int dxy[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //이동하는 방향
shark shk[512];

int isvalid(int n, int x, int y) {
    //위치가 유효한지 검사
    if (x <= 0 || y <= 0 || x > n || y > n) return 0;
    return 1;
}

int main(void) {
    int n, m, k, p, sce;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &p);
            if (p) {
                space[i][j] = (p << 16) + 1;
                shk[p].x = i;
                shk[p].y = j;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &shk[i].d);
        shk[i].n = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                scanf("%d", &shk[i].pri[j][k]);
            }
        }
    }
    for (int tm = 1; tm <= 1000; tm++) {
        for (int i = 1; i <= m; i++) {
            p = 0;
            for (int j = 1; j <= 4; j++) {
                if (!isvalid(n, shk[i].x + dxy[shk[i].pri[shk[i].d][j]][0],
                    shk[i].y + dxy[shk[i].pri[shk[i].d][j]][1])) continue;
                sce = (space[shk[i].x + dxy[shk[i].pri[shk[i].d][j]][0]][shk[i].y + dxy[shk[i].pri[shk[i].d][j]][1]] & 65535);
                if (sce <= tm - k || sce == 0) {
                    //냄새가 유효기간이 다했거나 없던 칸의 경우
                    shk[i].x += dxy[shk[i].pri[shk[i].d][j]][0];
                    shk[i].y += dxy[shk[i].pri[shk[i].d][j]][1];
                    shk[i].d = shk[i].pri[shk[i].d][j];
                    p = 1;
                    break;
                }
            }
            if (p) continue;
            for (int j = 1; j <= 4; j++) {
                if (!isvalid(n, shk[i].x + dxy[shk[i].pri[shk[i].d][j]][0],
                    shk[i].y + dxy[shk[i].pri[shk[i].d][j]][1])) continue;
                if ((space[shk[i].x + dxy[shk[i].pri[shk[i].d][j]][0]][shk[i].y + dxy[shk[i].pri[shk[i].d][j]][1]] >> 16)
                    == shk[i].n) {
                    //자신의 칸이 있던 경우
                    shk[i].x += dxy[shk[i].pri[shk[i].d][j]][0];
                    shk[i].y += dxy[shk[i].pri[shk[i].d][j]][1];
                    shk[i].d = shk[i].pri[shk[i].d][j];
                    p = 1;
                    break;
                }
            }
            if (!p) {
                while (k <= 3);
                return 3;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (stmp[shk[i].x][shk[i].y]) {
                //쫓겨나게 되는 상어
                m--;
                for (int j = i; j <= m; j++) shk[j] = shk[j + 1];
                if (m == 1) {
                    printf("%d", tm);
                    return 0;
                }
                i--;
                continue;
            }
            stmp[shk[i].x][shk[i].y] = shk[i].n;
            space[shk[i].x][shk[i].y] = (shk[i].n << 16) + tm + 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) stmp[i][j] = 0;
        }
    }
    printf("-1");
    return 0;
}