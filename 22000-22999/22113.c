#include <stdio.h>

/*
문제 : N(N <= 100)개의 버스에 대한 환승 표와 환승 계획이 주어질 때, 주어진 순서대로 환승 시 환승 요금의 합을 구한다.

해결 방법 : 주어진 환승 계획을 차례로 환승표에 넣고 확인한 값을 전부 더해주면 된다.

주요 알고리즘 : 구현

출처 : 연세대M 2021 2회 A번
*/

int a[128][128], seq[128];

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &seq[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i < m; i++) {
        r += a[seq[i - 1]][seq[i]];
    }
    printf("%d", r);
    return 0;
}