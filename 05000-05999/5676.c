#include <stdio.h>
#define SZ 131072

/*
문제 : N(N <= 100000)개의 정수로 이루어진 수열이 주어질 때, K(K <= 100000)개의 쿼리에 응답한다.
C: i번째 수를 X로 바꾼다.
P: i번째부터 j번째 수까지의 곱이 0인지 음수인지 양수인지 구한다.

해결 방법 : 세그먼트 트리 2개를 이용해서 한개는 각 구간의 음수의 개수를 저장하고, 한개는 0의 개수를 저장한다.
P가 들어올 때 마다 해당 범위의 수를 확인해서 0이 하나라도 있으면 0을 출력하고, 그 외에는 음수의 개수를 세서
홀수개 있으면 음수, 짝수개 있으면 양수를 출력한다. C가 들어올 때에는 들어오는 수에 따라 적절히
경우를 분류해서 음수와 0의 개수를 바꾸어 주면 된다.

주요 알고리즘 : 자료 구조, 세그먼트 트리

출처 : Latin 2012 I번
*/

int seg[SZ * 2], seg2[SZ * 2];

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

long long getsum2(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg2[p];
    return getsum2(x, y, s, (s + e) >> 1, p << 1) + getsum2(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void upd2(int a, int b) {
    seg2[a + SZ] = b;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg2[i] = seg2[i << 1] + seg2[(i << 1) + 1];
    }
}

int main(void) {
    int n, k, x, y;
    char o;
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x == 0) upd2(i, 1);
            else upd2(i, 0);
            if (x < 0) upd(i, 1);
            else upd(i, 0);
        }
        for (int i = 0; i < k; i++) {
            scanf(" %c %d %d", &o, &x, &y);
            if (o == 'C') {
                if (y < 0) upd(x, 1);
                else upd(x, 0);
                if (y == 0) upd2(x, 1);
                else upd2(x, 0);
            }
            else if (o == 'P') {
                if (getsum2(x, y, 0, SZ - 1, 1) > 0) printf("0");
                else if (getsum(x, y, 0, SZ - 1, 1) & 1) printf("-");
                else printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}