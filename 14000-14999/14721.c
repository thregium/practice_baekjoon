#include <stdio.h>

/*
문제 : N(N <= 100)개의 자연수 데이터 X_i, Y_i(X_i, Y_i <= 1000)가 주어질 때, 가장 Y = ax + b에 대해
가장 RSS가 작은 a, b를 구한다. 그러한 쌍이 여러 개인 경우는 주어지지 않는다.
A와 B는 1 이상 100 이하의 자연수이다.

해결 방법 : 모든 가능한 A, B에 대해 RSS를 구해본 다음 가장 작을 때의 A, B를 구하면 된다.
RSS를 구할 때 오버플로가 되지 않도록 주의한다.

주요 알고리즘 : 브루트 포스

출처 : 충남대 1회 F번
*/

int wrk[128][2];

long long f(int x, int a, int b) {
    return (long long)a * x + b;
}

long long sqr(long long x) {
    return x * x;
}

int main(void) {
    int n, ba = -1, bb = -1;
    long long rss = 0, best = (1LL << 60);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wrk[i][0], &wrk[i][1]);
    }
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            rss = 0;
            for (int i = 0; i < n; i++) {
                rss += sqr(wrk[i][1] - f(wrk[i][0], a, b));
            }
            if (rss < best) {
                best = rss;
                ba = a;
                bb = b;
            }
        }
    }
    if (ba < 0) return 1;
    printf("%d %d", ba, bb);
    return 0;
}