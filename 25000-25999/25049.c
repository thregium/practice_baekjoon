#include <stdio.h>
#define INF 1234567890987654321

/*
문제 : N(N <= 500000)개의 노래에 대해 각 노래의 선호도(|| <= 10^9)가 주어지면
들은 모든 노래의 선호도 합의 최댓값을 구한다.
노래는 차례로 듣되 2번까지 앞으로(또는 같은 노래로) 되돌아갈 수 있다. 또한, 한 노래를 3번 이상 들을 수 없다.

해결 방법 : 우선 모든 노래를 1번, 또는 2번만 들을 수 있다는 것을 알 수 있다.
2번 듣는 노래는 연결된 2개 이상의 덩어리여야 하며, 이는 5개의 상태를 가지는 DP를 통해 간단히 구할 수 있다.

주요 알고리즘 : DP

출처 : DGIST 2022 F번
*/

int p[524288];
long long mem[524288][7];

long long big(long long a, long long b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j < 7; j++) mem[i][j] = -INF;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        mem[i][1] = big(mem[i - 1][0], mem[i - 1][1]) + p[i];
        mem[i][2] = big(mem[i - 1][1], mem[i - 1][2]);
        mem[i][3] = big(mem[i - 1][2], mem[i - 1][3]) + p[i];
        mem[i][4] = big(mem[i - 1][3], mem[i - 1][4]);
        sum += p[i];
    }
    printf("%lld", sum + big(big(big(mem[n][0], mem[n][1]), big(mem[n][2], mem[n][3])), mem[n][4]));
    return 0;
}