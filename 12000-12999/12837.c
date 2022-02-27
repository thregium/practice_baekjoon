#include <stdio.h>
#define SZ 1048576

/*
문제 : 길이 N(N <= 10^6)의 0으로 초기화된 배열이 주어질 때, Q(Q <= 100000)개의 쿼리에 응답한다.
1. 배열의 P번째 값에 X(|X| <= 2 * 10^9)를 더한다.
2. 배열의 P번째부터 Q번째까지 값의 합을 구한다.

해결 방법 : 세그먼트 트리를 이용한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리
*/

long long seg[SZ * 2];

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void upd(int a, int b) {
    seg[a + SZ] += b;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, q, o, x, y;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &o, &x, &y);
        if (o == 1) upd(x, y);
        else printf("%lld\n", getsum(x, y, 0, SZ - 1, 1));
    }
    return 0;
}