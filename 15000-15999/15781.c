#include <stdio.h>

/*
문제 : N(N <= 1000)개의 자연수(<= 10^9) 중 최댓값과 M(M <= 1000)개의 자연수(<= 10^9) 중 최댓값의 합을 구한다.

해결 방법 : 각각의 최댓값을 구한 다음 더하면 된다.

주요 알고리즘 : 구현

출처 : 인하대 2018 B번
*/

int main(void) {
    int n, m, x, hr = -1, ar = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > hr) hr = x;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (x > ar) ar = x;
    }
    if (hr < 0 || ar < 0) return 1;
    printf("%d", hr + ar);
    return 0;
}