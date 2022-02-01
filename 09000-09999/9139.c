#include <stdio.h>
#define SZ 131072

/*
문제 : 길이 N(N <= 100000)의 1에서 N까지의 자연수로 이루어진 순열이 주어질 때,
이 순열이 1부터 N까지 차례로 올라가는 순열에서 서로 다른 3개의 수 (a, b, c)에 대해
순서를 (c, a, b)로 바꾸는 연산을 반복하여 만들 수 있는 지 구한다.

해결 방법 : 각 자리마다의 나올 수 있는 해당 수보다 작은 수의 가짓수를 전부 더한 것이 홀수인 경우
그러한 순열을 만들 수 없고, 짝수인 경우 만들 수 있다.
이는 세그먼트 트리를 통해 각 자리마다 앞에 있는 아직 사용하지 않은 수의 개수를 확인하여 구할 수 있다.

주요 알고리즘 : 자료 구조, 세그먼트 트리

출처 : CTU 2001 E번
*/

int a[103000], seg[SZ * 2];

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
    int n;
    long long r;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\e.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\e_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) upd(i, 1);
        r = 0;
        for (int i = 1; i <= n; i++) {
            r += getsum(1, a[i] - 1, 0, SZ - 1, 1);
            upd(a[i], 0);
        }
        if (r & 1) printf("Matfyzacci maji smulu.\n");
        else printf("Permutaci lze prevest.\n");
    }
    return 0;
}