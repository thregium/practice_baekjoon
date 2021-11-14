#include <stdio.h>
#define SZ 1048576

/*
문제 : N(N <= 10^6)개의 자연수로 이루어진 수열에서(0으로 초기화된 상태) M(M <= 10^6)개의 쿼리에 응답한다.
0. [A, B]의 합을 구한다.
1. A번째 수를 B(B <= 100000)로 바꾼다.

해결 방법 : 세그먼트 트리를 이용한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리
*/

long long seg[SZ * 2];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void upd(int a, int b) {
    seg[a + SZ] = b;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, m, o, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &a, &b);
        if (o == 0) {
            if (a > b) swap(&a, &b);
            printf("%lld\n", getsum(a, b, 0, SZ - 1, 1));
        }
        else if (o == 1) {
            upd(a, b);
        }
    }
    return 0;
}