#include <stdio.h>
#define SZ 131072

/*
문제 : N(N <= 100000)개의 수로 이루어진 수열이 주어질 때, 다음 쿼리에 응답한다.
1. L번째부터 R번째까지의 수열이 비내림차순인지 확인한다.
2. L번째와 R번째의 값을 바꾼다.

해결 방법 : L번째부터 R번째까지의 수열이 비내림차순인 것은 L번째와 R번째 사이의 모든 인접한 수들이 서로 같거나
오른쪽 수가 더 큰 경우이다. 이는 모든 칸에 대해 오른쪽 수와 비교해 오른쪽 수가 같거나 큰 경우로 수열을 만든 다음
L번째와 R번째 사이의 구간합이 R - L과 같은지 확인함을 통해 해결 가능하다.
이 연산은 세그먼트 트리를 이용하면 쉽게 할 수 있다.

L번째와 R번째의 값을 바꾸는 연산은 수열의 값을 바꿔놓은 다음, 해당 수 주변 칸과 비교해서 주변의 값과 구간합을
업데이트 하는 방식으로 구현 가능하다.

주요 알고리즘 : 자료 구조, 세그먼트 트리

출처 : KAIST 2016S B번
*/

int a[SZ], seg[SZ * 2];

void upd(int x, int y) {
    seg[SZ + x] = y;
    for (int i = (SZ + x) >> 1; i; i >>= 1) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
}

int find(int l, int r, int sl, int sr, int p) {
    if (r < sl || sr < l || l > r) return 0;
    if (l <= sl && sr <= r) return seg[p];
    return find(l, r, sl, (sl + sr) >> 1, p << 1) + find(l, r, ((sl + sr) >> 1) + 1, sr, (p << 1) + 1);
}

int main(void) {
    int n, xy, q, l, r, t;
    scanf("%d %d", &n, &xy);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= a[i - 1]) upd(i - 1, 1);
    }
    for (int i = 0; i < xy; i++) {
        scanf("%d %d %d", &q, &l, &r);
        if (q == 1) {
            if (find(l, r - 1, 0, SZ - 1, 1) == r - l) printf("CS204\n");
            else printf("HSS090\n");
        }
        else {
            t = a[l];
            a[l] = a[r];
            if (a[l] >= a[l - 1]) upd(l - 1, 1);
            else upd(l - 1, 0);
            if (a[l + 1] >= a[l]) upd(l, 1);
            else upd(l, 0);
            a[r] = t;
            if (a[r] >= a[r - 1]) upd(r - 1, 1);
            else upd(r - 1, 0);
            if (a[r + 1] >= a[r]) upd(r, 1);
            else upd(r, 0);
        }
    }
    return 0;
}