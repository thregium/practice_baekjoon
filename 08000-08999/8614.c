#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 자연수(<= 10^9)가 주어질 때, M(M <= 10^9) 이상의 자연수를 포함하는
구간의 개수를 구한다.

해결 방법 : 전체 구간의 개수(sum(1, N))를 구한 다음, M 이상의 자연수가 없는 구간들을 빼 나가면 된다.
자연수가 없는 연속 구간의 길이를 구한 다음, sum(1, len)을 하면 그것이 그 구간의 개수와 같다.

주요 알고리즘 : 수학, 조합론

출처 : JPOI 2009 2-3번
*/

long long getsum(long long n) {
    return (n * (n + 1)) >> 1;
}

int main(void) {
    int n, m, h, c = 0;
    long long r;
    scanf("%d %d", &n, &m);
    r = getsum(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h);
        if (h < m) c++;
        else {
            r -= getsum(c);
            c = 0;
        }
    }
    r -= getsum(c);
    printf("%lld", r);
    return 0;
}