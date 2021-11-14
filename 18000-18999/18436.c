#include <stdio.h>
#define MAX 131072

/*
문제 : N(N <= 100000)개의 자연수로 이루어진 배열이 주어질 때, M(M <= 100000)개의 다음 쿼리에 응답한다.
1. i번째 값을 v로 바꾼다.
2. i번째부터 j번째까지의 값 가운데 짝수인 값의 개수를 구한다.
3. i번째부터 j번째까지의 값 가운데 홀수인 값의 개수를 구한다.

해결 방법 : 세그먼트 트리를 이용해 홀수인 값의 개수를 저장하고 업데이트, 합 확인을 하면 된다.
일반적인 합 대신 2로 나눈 나머지를 저장해주면 된다.

주요 알고리즘 : 자료 구조, 세그먼트 트리
*/

long long seg[MAX * 2];

long long sum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return sum(x, y, s, (s + e) >> 1, p << 1) + sum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void update(int a, int b) {
    seg[a + MAX] = b;
    for (int i = (a + MAX) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, q, o, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &seg[i + MAX]);
        seg[i + MAX] &= 1;
    }
    for (int i = MAX - 1; i > 0; i--) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &o, &x, &y);
        if (o == 1) update(x, y & 1);
        else if (o == 2) printf("%lld\n", y - x + 1 - sum(x, y, 0, MAX - 1, 1));
        else printf("%lld\n", sum(x, y, 0, MAX - 1, 1));
    }
    return 0;
}