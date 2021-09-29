#include <stdio.h>

/*
문제 : N(N <= 20)개의 10^8 이하인 자연수들이 주어질 때, 올림을 하지 않고 집합 내의 모든 수들을 더할 수 있는 가장 큰
부분집합의 크기를 구한다.

해결 방법 : 2^N가지 모든 경우를 살펴본다. 각 경우에서 올림을 하지 않고 더할 수 있는지는
각 자연수들의 각 자리의 합을 구해서 모든 경우의 합이 10보다 작은 경우인지 살펴보면 알 수 있다.

주요 알고리즘 : 수학, 브루트 포스

출처 : USACO 2011D B3번
*/

int weight[32];
int b10[9] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

int main(void) {
    int n, r = 0, x, t, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        t = 1;
        s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) s++;
        }
        if (s <= r) continue;
        for (int j = 0; j < 9; j++) {
            x = 0;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) {
                    x += (weight[k] / b10[j] % 10);
                }
            }
            if (x >= 10) {
                t = 0;
                break;
            }
        }
        if (t) r = s;
    }
    printf("%d", r);
    return 0;
}