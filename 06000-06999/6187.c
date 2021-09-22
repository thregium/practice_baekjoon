#include <stdio.h>

/*
문제 : N(N <= 16)개의 자연수 합이 C(C <= 5000)를 넘지 않는 가장 큰 수가 되도록 할 때의 합을 구한다.

해결 방법 : 2^N가지 경우에 대해 비트마스킹을 통해 모든 경우를 확인한 다음 C 이하의 가장 큰 합을 구하면 된다.

주요 알고리즘 : 브루트 포스, 비트마스킹

출처 : USACO 2008O B2번
*/

int weight[32];

int main(void) {
    int c, n, r = 0, t;
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) t += weight[j];
        }
        if (t <= c && t > r) r = t;
    }
    printf("%d", r);
    return 0;
}