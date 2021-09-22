#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 20)마리의 소들의 키가 각각 주어질 때(<= 10^6), 소들의 키 합이 B보다 크게 하면서 B와의 차이가
가장 작은 경우의 차이를 구한다. 항상 B보다 큰 조합이 하나는 있도록 주어진다.

해결 방법 : 2^N가지의 경우를 비트마스킹을 통해 전부 시도해 보고 최솟값을 구하면 된다.

주요 알고리즘 : 브루트 포스, 비트마스킹

출처 : USACO 2007D B2번
*/

int h[32];

int main(void) {
    int n, b, s, r = INF;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) s += h[j];
        }
        if (s >= b && s - b < r) r = s - b;
    }
    printf("%d", r);
    return 0;
}