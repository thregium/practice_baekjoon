#include <stdio.h>

/*
문제 : N부터 M(N, M <= 10^6)까지의 수에 있는 0의 개수를 센다.

해결 방법 : 사이에 있는 모든 수에 대해 0의 개수를 직접 세주면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : IDI 2014 C번
*/

int getzeros(int x) {
    int r = 0;
    if (!x) return 1;
    while (x) {
        if (x % 10 == 0) r++;
        x /= 10;
    }
    return r;
}

int main(void) {
    int t, n, m, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        cnt = 0;
        for (int i = n; i <= m; i++) {
            cnt += getzeros(i);
        }
        printf("%d\n", cnt);
    }
    return 0;
}