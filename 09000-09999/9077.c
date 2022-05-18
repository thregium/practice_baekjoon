#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100000)개의 지뢰가 평면 상의 10000 이내 음이 아닌 정수 점에 있다.
10 * 10 크기의 범위 안에 지뢰가 최대 몇 개 있는 지 구한다. 모든 지뢰는 서로 다른 점에 있다.

해결 방법 : 각 좌표의 누적 합 배열을 만들어 각 10 * 10 범위 내의 지뢰를 (비교적) 빠르게 찾을 수 있다.
각 지뢰에 대해 주위 5 * 5 칸을 중심으로 하는 모든 사각형 범위에 대해 지뢰 개수를 세고
그 가운데 가장 많은 것의 개수를 세면 답이 된다.

주요 알고리즘 : 브루트 포스, 누적 합

출처 : Seoul 2004I C번
*/

int mine[10240][10240], pos[103000][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int getsum(int x1, int y1, int x2, int y2) {
    return mine[x2][y2] - mine[x1 - 1][y2] - mine[x2][y1 - 1] + mine[x1 - 1][y1 - 1];
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pos[i][0], &pos[i][1]);
            pos[i][0] += 15, pos[i][1] += 15;
            mine[pos[i][0]][pos[i][1]]++;
        }
        for (int i = 1; i < 10240; i++) {
            for (int j = 1; j < 10240; j++) mine[i][j] += mine[i][j - 1];
        }
        for (int i = 1; i < 10240; i++) {
            for (int j = 1; j < 10240; j++) mine[j][i] += mine[j - 1][i];
        }

        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = -5; j <= 5; j++) {
                for (int k = -5; k <= 5; k++) {
                    r = big(r, getsum(pos[i][0] + j - 5, pos[i][1] + k - 5,
                        pos[i][0] + j + 5, pos[i][1] + k + 5));
                }
            }
        }
        printf("%d\n", r);

        memset(mine, 0, sizeof(mine));
    }
    return 0;
}