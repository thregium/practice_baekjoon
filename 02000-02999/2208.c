#include <stdio.h>
#define SZ 131072

/*
문제 : N(N <= 100000)개의 보석이 일렬로 있다. M(M <= N)개 이상의 연속된 보석을 단 한번만
주울 수 있다면 얻을 수 있는 이익의 최댓값을 구한다. 보석을 줍지 않을 수 있고,
이익의 절댓값은 2000 이하다.

해결 방법 : 누적 합을 통해 각 지점(0번째 포함)에서 그 지점 + M번째부터 마지막 지점 사이 중 누적 합의 최댓값
의 차이를 각각 구하고, 그 중 가장 큰 값을 구하면 된다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 누적 합
*/

int gem[103000], seg[SZ << 1];

int big(int a, int b) {
    return a > b ? a : b;
}

long long seg_query(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return -1012345678;
    if (x <= s && y >= e) return seg[p];
    return big(seg_query(x, y, s, (s + e) >> 1, p << 1), seg_query(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1));
}

int main(void) {
    int n, m, res = 0, tres;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < SZ * 2; i++) seg[i] = -1012345678;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &gem[i]);
        gem[i] += gem[i - 1];
        seg[SZ + i] = gem[i];
    }
    for (int i = SZ - 1; i >= 1; i--) {
        seg[i] = big(seg[i << 1], seg[(i << 1) + 1]);
    }
    for (int i = 0; i <= n - m; i++) {
        tres = seg_query(i + m, n, 0, SZ - 1, 1) - gem[i];
        if (tres > res) res = tres;
    }
    printf("%d", res);
    return 0;
}