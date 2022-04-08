#include <stdio.h>
#define INF 1012345678
#define SZ 131072

/*
문제 : N(N <= 100000)개의 물건이 있고, M(M <= 100000)명의 입찰자가 있다. 각 물건의 초기 금액은
a_i(a_i <= 10^9)이고, 각 입찰자가 원하는 금액은 b_i(b_i <= 10^9)이다.
각 입찰자는 원하는 금액보다 작은 첫 물건에 입찰을 한다. 입찰을 할 물건이 없다면 입찰을 하지 않는다.
이때, 입찰이 되는 물건의 개수를 구한다.

해결 방법 : 각 입찰자가 입찰할 물건을 빠르게 구하여 답을 찾을 수 있다.
각 입찰자가 입찰할 물건은 처음부터 봤을 때 최솟값이 b_i보다 작은 첫 위치의 물건이다.
왼쪽부터의 최솟값은 세그먼트 트리와 이분 탐색을 통해 찾을 수 있다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 이분 탐색

출처 : INC 2020 H번
*/

int a[103000], b[103000], chk[103000], seg[SZ * 2];

int small(int a, int b) {
    return a < b ? a : b;
}

void upd(int p, int x) {
    seg[p + SZ] = x;
    for (int i = (p + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = small(seg[i << 1], seg[(i << 1) + 1]);
    }
}

int getsml(int s, int e, int ss, int se, int p) {
    if (e < ss || se < s) return INF;
    else if (s <= ss && se <= e) return seg[p];
    else return small(getsml(s, e, ss, (ss + se) >> 1, p << 1),
        getsml(s, e, ((ss + se) >> 1) + 1, se, (p << 1) + 1));
}

int main(void) {
    int n, m, lo, hi, mid, r = 0;
    for (int i = 0; i < SZ * 2; i++) seg[i] = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
        seg[i + SZ] = a[i];
    }
    for (int i = SZ - 1; i > 0; i--) seg[i] = small(seg[i << 1], seg[(i << 1) + 1]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        lo = 0, hi = n;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (getsml(0, mid, 0, SZ - 1, 1) < b[i]) hi = mid;
            else lo = mid + 1;
        }
        if (lo == n) continue;
        else {
            r += (!chk[lo]);
            chk[lo] = 1;
            upd(lo, b[i]);
        }
    }
    printf("%d", r);
    return 0;
}