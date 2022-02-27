#include <stdio.h>
#define INF 1012345678
#define SZ 131072

/*
문제 : N(N <= 100000)개의 10^9 이하인 자연수로 이루어진 수열에서 M(M <= 100000)개의 쿼리에 응답한다.
1. X번째 자연수를 Y로 바꾼다.
2. [X, Y] 범위에 있는 자연수 가운데 가장 작은 자연수 중 가장 왼쪽에 있는 자연수의 번호를 구한다.

해결 방법 : 세그먼트 트리를 이용한다. 범위를 벗어나는 경우에 유의한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리
*/

int a[SZ], seg[SZ * 2];

long long getsmall(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    int l = getsmall(x, y, s, (s + e) >> 1, p << 1);
    int r = getsmall(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
    if (a[l] <= a[r]) return l;
    else return r;
}

void upd(int x, int y) {
    a[x] = y;
    for (int i = (x + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = a[seg[i << 1]] <= a[seg[(i << 1) + 1]] ? seg[i << 1] : seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, m, o, x, y;
    scanf("%d", &n);
    for (int i = 0; i < SZ; i++) {
        a[i] = INF;
        seg[SZ + i] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = SZ - 1; i >= 1; i--) {
        seg[i] = a[seg[i << 1]] <= a[seg[(i << 1) + 1]] ? seg[i << 1] : seg[(i << 1) + 1];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &x, &y);
        if (o == 1) upd(x, y);
        else printf("%lld\n", getsmall(x, y, 0, SZ - 1, 1));
    }
    return 0;
}