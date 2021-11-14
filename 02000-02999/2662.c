#include <stdio.h>

/*
문제 : 투자 금액 N(N <= 300)과 투자할 수 있는 기업들 M(M <= 20)개에서 각 투자 금액 별 이익이 주어지면
N의 금액으로 최대 이익을 얻도록 투자하는 방법과 그때의 이익을 구한다.

해결 방법 : 냅색 문제를 응용해 풀 수 있다. 확인한 마지막 기업들과 금액에 따라 얻을 수 있는 최대 금액을 구한다.
그러면 마지막 기업의 투자액 N일 때가 가장 이익이 큰 경우인데, 여기서 역으로 DP 배열을 확인해 나가면서
해당 기업에 해당 금액을 투자했을 때가 DP 배열을 지나는 경우에 대해 각 기업의 투자 금액을 저장한다.
이를 다시 원래 순서대로 출력하면 된다.

주요 알고리즘 : DP, 냅색, 역추적

출처 : 정올 1997 중2번
*/

int prof[32][384], mem[32][384], res[32];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, x, t;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= m; j++) {
            scanf("%d", &prof[j][i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                mem[i][j] = big(mem[i][j], mem[i - 1][j - k] + prof[i][k]);
            }
        }
    }

    x = n;
    for (int i = m; i > 0; i--) {
        t = 0;
        for (int j = 0; j <= x; j++) {
            if (mem[i - 1][x - j] + prof[i][j] == mem[i][x]) {
                t = 1;
                res[i] = j;
                x -= j;
                break;
            }
        }
        if (!t) return 1;
    }
    printf("%d\n", mem[m][n]);
    for (int i = 1; i <= m; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}