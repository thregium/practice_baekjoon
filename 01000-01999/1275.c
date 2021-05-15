#include <stdio.h>
#define MAX 131072

/*
문제 : N(N <= 100000)개의 수로 이루어진 배열이 있다. 이 배열에서 X번째 수부터 Y번째 수까지 합을 구한 다음
A번째 수를 B로 바꾸는 쿼리에 응답한다.

해결 방법 : 세그먼트 트리를 이용해 구간합을 구하고 수를 업데이트하면 된다.

주요 알고리즘 : 자료 구조, 세그먼트 트리
*/

long long seg[MAX * 2];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

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
    int n, q, x, y, a, b;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &seg[i + MAX]);
    }
    for (int i = MAX - 1; i > 0; i--) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if (x > y) swap(&x, &y);
        printf("%lld\n", sum(x - 1, y - 1, 0, MAX - 1, 1));
        update(a - 1, b);
    }
    return 0;
}