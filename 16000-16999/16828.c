#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 10000)개의 선물이 있고, 각 선물은 S_i(S_i <= 10000)만큼의 무게와 P_i(P_i <= 10000)만큼의
가치를 갖고 있다. 이때, C_i(C_i <= 10000)의 무게 제한 내에서 M(M <= 10000)명 이하의 각 사람에게
선물을 나누어 주려고 한다. 나누어 주는 사람 수 i에 대해 모든 물건은 i개 또는 0개 선택해야 한다.
이때, M 이하의 모든 사람 수에 대해 나누어 줄 수 있는 최대 가치 합을 각각 구한다.

해결 방법 : 1명일 때에는 간단한 냅색 문제와 같다. 2명 이상이 되면 모든 물건을 i명에게 나누어 주어야 하므로
C / i의 용량 제한일 때의 최댓값에서 i를 곱한 것의 값과 같다.

주요 알고리즘 : DP, 냅색

출처 : JAG 2018S3 C번
*/

int mem[2][10240];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int c, n, m, s, p;
    scanf("%d %d %d", &c, &n, &m);
    for (int i = 1; i <= c; i++) mem[0][i] = -INF;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &p);
        for (int j = s; j <= c; j++) {
            mem[1][j] = big(mem[1][j], mem[0][j - s] + p);
        }
        for (int j = s; j <= c; j++) mem[0][j] = mem[1][j];
    }
    for (int i = 1; i <= c; i++) mem[0][i] = big(mem[0][i], mem[0][i - 1]);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", mem[0][c / i] * i);
    }
    return 0;
}
