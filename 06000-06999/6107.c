#include <stdio.h>

/*
문제 : R * C(R, C <= 50) 크기의 자연수가 적힌 격자에서 상하좌우대각선으로 인접한 2칸 이상이 같은 수 가운데 가장 큰 수를 구한다.

해결 방법 : 모든 칸에서 주위 8칸을 살펴보며 같은 수가 적힌 칸이 있는 칸의 값들 가운데 가장 큰 것을 고르면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : USACO 2009M B2번
*/

int depth[64][64];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int main(void) {
    int r, c, t, best = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &depth[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            t = 0;
            for (int d = 0; d < 8; d++) {
                if (i + dxy[d][0] < 0 || i + dxy[d][0] >= r || j + dxy[d][1] < 0 || j + dxy[d][1] >= c) continue;
                if (depth[i + dxy[d][0]][j + dxy[d][1]] == depth[i][j]) t = 1;
            }
            if (t && depth[i][j] > best) best = depth[i][j];
        }
    }
    printf("%d", best);
    return 0;
}