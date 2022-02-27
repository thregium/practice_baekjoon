#include <stdio.h>
#include <stdlib.h>
#define SZ 131072

/*
문제 : 길이 N(N <= 100000)의 N 이하의 자연수로 이루어진 수열 A가 주어질 때,
이 수열에서 i < j < k이며 A_i > A_j > A_k인 순서쌍의 개수를 구한다.

해결 방법 : 세그먼트 트리를 이용하여 각 j값마다 (i, j) 순서쌍의 개수를 구하고,
같은 방법으로 (i, j, k) 순서쌍의 개수를 구하면 된다. (i, j) 순서쌍은 앞에 나온 수들 가운데
현재 값보다 큰 값의 개수를 구하는 방식으로 구하면 된다.

주요 알고리즘 : 자료 구조, 세그먼트 트리

출처 : NCPC 2011 B번
*/

long long a[103000], mem[16][103000], seg[SZ * 2];

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return (getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1));
}

void upd(int a, int b) {
    seg[a + SZ] = (seg[a + SZ] + b);
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = (seg[i << 1] + seg[(i << 1) + 1]);
    }
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        //a[i] = rand() % 100;
        scanf("%lld", &a[i]);
        mem[1][i] = 1;
    }
    for (int i = 2; i <= 3; i++) {
        for (int j = 0; j < SZ * 2; j++) seg[j] = 0;
        for (int j = 1; j <= n; j++) {
            mem[i][j] = getsum(a[j] + 1, SZ - 1, 0, SZ - 1, 1);
            upd(a[j], mem[i - 1][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        r = (r + mem[3][i]);
    }
    printf("%lld", r);
    return 0;
}