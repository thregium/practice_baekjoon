#include <stdio.h>

/*
문제 : M(M <= 2000)개의 자연수 가운데 N(N <= 10)개를 뽑는 방법의 가짓수를 구한다. 단, 뽑은 수는 이전 수의 2배 이상이어야 한다.

해결 방법 : 다이나믹 프로그래밍을 통해 해결한다. 마지막으로 뽑은 수와 뽑은 수의 개수를 변수로 두면,
각 경우에서 뽑는 수의 개수는 (현재 수 / 2에서 1개 덜 뽑았을 때의 개수(현재 수를 뽑는 경우)) +
(현재 수 - 1에서 현재만큼 뽑았을 때의 개수(현재 수를 뽑지 않은 경우))이다.

주요 알고리즘 : DP

출처 : GNY 2004 C번 // PacNW 2004 C번
*/

long long mem[12][2048];

int main(void) {
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\c.in", "r", stdin);
    for (int i = 0; i <= 2000; i++) mem[0][i] = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 2000; j++) {
            mem[i][j] = mem[i - 1][j >> 1] + mem[i][j - 1];
        }
    }
    int t, n, m;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        printf("%lld\n", mem[n][m]);
    }
    return 0;
}