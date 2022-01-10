#include <stdio.h>

/*
문제 : W * H(W, H <= 100) 크기의 땅의 정수 점 N(N <= 500)개에 감나무가 심어져 있다. S * T 크기의 직사각형 가운데
감나무가 가장 많은 직사각형에는 감나무가 몇 개 있는 지 구한다.

해결 방법 : W와 H의 크기가 작기 때문에 모든 가능한 직사각형에 대해 조사해 보며 감나무의 개수를 구해나가면 된다.

주요 알고리즘 : 브루트 포스

출처 : JDC 2003 B번
*/

int pers[128][128];

int main(void) {
    int n, w, h, s, t, r, cnt;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d %d", &w, &h);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &s, &t);
            pers[s][t]++;
        }
        scanf("%d %d", &s, &t);

        r = 0;
        for (int i = 1; i <= w - s + 1; i++) {
            for (int j = 1; j <= h - t + 1; j++) {
                cnt = 0;
                for (int ii = i; ii < i + s; ii++) {
                    for (int jj = j; jj < j + t; jj++) cnt += pers[ii][jj];
                }
                if (cnt > r) r = cnt;
            }
        }
        printf("%d\n", r);

        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) pers[i][j] = 0;
        }
    }
    return 0;
}