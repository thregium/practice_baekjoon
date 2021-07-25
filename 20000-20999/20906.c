#include <stdio.h>

/*
문제 : 모래가 S(S <= 10^6)초 분량만큼 들어있는 모래시계가 있다. 처음에는 모래가 모두 모래시계의 아랫부분에 있고,
N(N <= 1000)회 주어진 시각에 모래시계를 되집는다고 할 때, T(T <= 10^6)초를 기준으로 몇 초 뒤에 모래가 전부 내려가는지 구한다.

해결 방법 : 모래시계를 뒤집을 때 마다 따라가며 모래의 양을 조절하고 모래시계를 뒤집는다.
마지막 뒤집을 때의 모래의 양을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : GCPC 2020 F번
*/

int a[1024];

int main(void) {
    int t, s, n, r;
    scanf("%d %d %d", &t, &s, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    r = s;
    for (int i = 2; i <= n; i++) {
        r -= a[i] - a[i - 1];
        if (r < 0) r = 0;
        r = s - r;
    }
    r -= t - a[n];
    if (r < 0) r = 0;
    printf("%d", r);
    return 0;
}