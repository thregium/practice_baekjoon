#include <stdio.h>

/*
문제 : A * B(A, B <= 16) 크기의 격자판에 N(N <= 40)개의 장애물이 있다.
장애물들을 지나지 않고 격자판의 (1, 1)에서 (A, B)까지 최단거리로 이동하는 방법의 수를 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 구할 수 있다.
장애물이 있는 장소를 제외하고 왼쪽과 아래쪽의 값을 더해나가면 된다.

주요 알고리즘 : DP

출처 : JOI 2007예 6번
*/

long long mem[32][32], obst[32][32];

int main(void) {
    int a, b, n, x, y;
    for (int tt = 0; tt < 1; tt++) {
        scanf("%d %d", &a, &b);
        if (a == 0) break;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            obst[x][y] = 1;
        }

        mem[1][1] = 1;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (!obst[i][j + 1]) mem[i][j + 1] += mem[i][j];
                if (!obst[i + 1][j]) mem[i + 1][j] += mem[i][j];
            }
        }
        printf("%lld\n", mem[a][b]);
        for (int i = 1; i <= a + 1; i++) {
            for (int j = 1; j <= b + 1; j++) {
                mem[i][j] = 0;
                obst[i][j] = 0;
            }
        }
    }
    return 0;
}