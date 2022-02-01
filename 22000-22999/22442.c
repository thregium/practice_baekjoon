#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 10)개의 종목이 있고, D(D <= 10)일간 각 종목의 가격 변화가 주어진다.
초기 자금 X(X <= 100000)로 각 종목들에 자유롭게 투자할 때, D일 후 가능한 최고 자산을 구한다.
답은 100000을 넘지 않는다. 각 종목을 투자할 때에는 수수료가 들지 않으며, 정수 단위로만 살 수 있다.

해결 방법 : 수수료가 들지 않기 때문에 각 날마다 단타로 가장 수익이 많이 나게 자산을 사고 파는 것이
효율적임을 알 수 있다. 각 날마다 자산을 사고 파는 방법은 냅색 문제와 같이
다이나믹 프로그래밍을 하여 최고 수익을 찾아날 수 있다. 그러면 그 수익을 다음 날의 자산으로 하여
마지막 날까지 반복한 다음 얻어지게 되는 자금을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, DP, 냅색

출처 : JAG 2013S3 A번
*/

int price[16][16], mem[103000];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, d, x, y, s, best;
    scanf("%d %d %d", &n, &d, &x);
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &price[i][j]);
        }
    }
    for (int i = 1; i < d; i++) {
        best = 0;
        for (int j = 1; j <= x; j++) mem[j] = -INF;
        mem[0] = 0;
        for (int j = 0; j < n; j++) {
            for (int k = price[i - 1][j]; k <= x; k++) {
                mem[k] = big(mem[k], mem[k - price[i - 1][j]] + price[i][j] - price[i - 1][j]);
            }
        }
        for (int j = 0; j <= x; j++) best = big(mem[j], best);
        x += best;
    }
    printf("%d\n", x);
    return 0;
}