#include <stdio.h>
#define MOD 1000000007

/*
문제 : 길이 N의 M(N, M <= 100)가지 문자를 모두 사용하여 만들어진 문자열은 몇 가지인 지 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 해결한다. 각 길이와 쓴 문자의 개수마다
가짓수를 저장해 나가면서 풀면 된다.

주요 알고리즘 : DP, 조합론

출처 : GKS 2014B A2번
*/

long long mem[128][128];

int main(void) {
    int t, n, m;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &m, &n);
        mem[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mem[i][j] = (mem[i - 1][j - 1] * (m - (j - 1)) + mem[i - 1][j] * j) % MOD;
            }
        }
        printf("Case #%d: %lld\n", tt, mem[n][m]);
    }
    return 0;
}