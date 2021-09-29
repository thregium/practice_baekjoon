#include <stdio.h>

/*
문제 : N * N(N <= 750) 크기의 달팽이를 출력한다. 왼쪽 위 칸에서 시작해 오른쪽으로 출발하고, 반시계방향으로 돌아가는 형태이다.

해결 방법 : 맨 왼쪽 위에서 좌표를 이동해가다가 범위 밖으로 나가거나 이미 수가 쓰인 지점마다 방향을 꺾어가면 된다.
방향 배열을 사용하면 조금 더 간단히 풀 수 있다.

주요 알고리즘 : 구현

출처 : USACO 2011M B3번
*/

int res[768][768];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, d = 0, x = 0, y = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n * n; i++) {
        res[x][y] = i;
        if (x + dxy[d][0] < 0 || y + dxy[d][1] < 0 || x + dxy[d][0] >= n || y + dxy[d][1] >= n) d = ((d + 1) & 3);
        else if (res[x + dxy[d][0]][y + dxy[d][1]]) d = ((d + 1) & 3);
        x += dxy[d][0];
        y += dxy[d][1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}