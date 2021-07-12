#include <stdio.h>

/*
문제 : N(N <= 64)자리의 자릿수가 줄어들지 않는 수의 개수를 구한다.

해결 방법 : 마지막 자리와 N에 따른 개수를 저장해둔다. 점화식은 이전 자리가 현재 마지막 자리 이하인 N - 1자리 수의 개수를 전부 더한 것이다.

주요 알고리즘 : DP

출처 : GNY 2010 E번
*/

long long mem[128][10];

int main(void) {
    int t, n;
    long long s;
    for (int i = 0; i < 10; i++) {
        mem[1][i] = 1;
    }
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                mem[i][j] += mem[i - 1][k];
            }
        }
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        s = 0;
        for (int i = 0; i < 10; i++) {
            s += mem[n][i];
        }
        printf("%lld\n", s);
    }
    return 0;
}