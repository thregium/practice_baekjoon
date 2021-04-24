#include <stdio.h>
#define MOD 1000000007

/*
문제 : 이항계수 nCk를 구한다.(n, k <= 1000)

해결 방법 : n과 k의 제한을 보면 다이나믹 프로그래밍을 통해 해결 가능하다.
nCk = (n-1)C(k-1) + (n-1)Ck와 같음을 이용한다.

주요 알고리즘 : 다이나믹 프로그래밍, 조합론

출처 : AIPO 2016P 6번
*/

int comb[1024][1024];

int main(void) {
    comb[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        comb[i][0] = comb[i - 1][0];
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
    int t, n, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        printf("%d\n", comb[n][k]);
    }
    return 0;
}