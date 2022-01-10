#include <stdio.h>

/*
문제 : N(N <= 20)개의 보석과 M(M <= 30)개의 이동 명령(동서남북 방향으로 자연수 칸만큼 이동)이 주어질 때,
로봇이 (10, 10)에서 모든 이동 명령을 시행하며 모든 보석을 모을 수 있는 지 구한다.
이동 중간에도 보석을 모을 수 있다. 모든 보석들은 (0, 0)과 (20, 20) 이내의 정사각형 범위 안에 있으며,
로봇의 모든 이동은 해당 범위 내에서만 이루어진다.

해결 방법 : 로봇의 이동을 시뮬레이션하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JDC 2006 A번
*/

int gem[32][2], earn[32];
int dxy[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int main(void) {
    int n, m, x, y, mov, dir = -1, res;
    char c;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &gem[i][0], &gem[i][1]);
            earn[i] = 0;
        }
        x = 10, y = 10;

        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf(" %c %d", &c, &mov);
            if (c == 'N') dir = 0;
            else if (c == 'E') dir = 1;
            else if (c == 'W') dir = 2;
            else if (c == 'S') dir = 3;
            else return 1;

            for (int j = 0; j < mov; j++) {
                x += dxy[dir][0];
                y += dxy[dir][1];
                for (int k = 0; k < n; k++) {
                    if (gem[k][0] == x && gem[k][1] == y) earn[k] = 1;
                }
            }
        }

        res = 1;
        for (int i = 0; i < n; i++) {
            if (!earn[i]) res = 0;
        }
        printf("%s\n", res ? "Yes" : "No");
    }
    return 0;
}