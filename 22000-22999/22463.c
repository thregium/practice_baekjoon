#include <stdio.h>

/*
문제 : N(N <= 5000)개의 지점(|| <= 10^9)에 보물이 묻혀있다. 이때, (X1, Y1), (X2, Y2) 사이의
직사각형 범위 안에 묻힌 보물의 개수를 M(M <= 500000)번 구한다. (시간 제한 5초)

해결 방법 : 시간 제한이 넉넉하기 때문에 브루트 포스로 풀면 된다.

주요 알고리즘 : 브루트 포스

출처 : JAG 2012S2 C번
*/

int tres[5120][2];

int main(void) {
    int n, m, x1, y1, x2, y2, r;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tres[i][0], &tres[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        r = 0;
        for (int j = 0; j < n; j++) {
            r += (x1 <= tres[j][0] & tres[j][0] <= x2 & y1 <= tres[j][1] & tres[j][1] <= y2);
        }
        printf("%d\n", r);
    }
    return 0;
}