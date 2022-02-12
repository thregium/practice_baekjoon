#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 격자에 흰색, 파란색, 빨간색이 칠해져 있다.
이 격자를 상하로 차례로 흰색, 파란색, 빨간색 순서로 나누고 다른 색의 개수를 구할 때,
가장 다른 색의 개수가 적은 경우의 다른 색 수를 구한다. 각 색의 줄은 높이 1 이상이어야 한다.

해결 방법 : 세 부분으로 나누는 모든 경우를 시도해보면 된다.

주요 알고리즘 : 브루트 포스

출처 : JOI 2016예 3번
*/

char flag[64][64];

int main(void) {
    int n, m, r = 103000, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", flag[i]);
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            t = 0;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l <= i; l++) {
                    if (flag[l][k] != 'W') t++;
                }
                for (int l = i + 1; l <= j; l++) {
                    if (flag[l][k] != 'B') t++;
                }
                for (int l = j + 1; l < n; l++) {
                    if (flag[l][k] != 'R') t++;
                }
            }
            if (t < r) r = t;
        }
    }
    if (r == 103000) return 1;
    printf("%d", r);
    return 0;
}