#include <stdio.h>
#define INF 1234567890987654321

/*
문제 : N(N <= 3000)개의 정수(|| <= 10^9)가 주어진다. 1번째와 마지막 수를 반드시 경유하고,
그 사이 수 간에는 사이의 이동 거리가 단조 감소해야 한다고 할 때, 경유한 정수의 합의 최댓값을 구한다.

해결 방법 : 각 (위치, 최소 이동 거리)를 상태로 하여 그때의 최댓값을 저장해가며
다이나믹 프로그래밍을 진행한다. 매번 최소 이동 거리만큼 앞 칸에 대해 그 거리 이상의 최댓값을
구하고 현재 위치의 값을 더해나가면 된다. 최댓값은 누적된 값을 통해 찾아야 시간 내에 들어올 수 있다.

주요 알고리즘 : DP, 누적 합?

출처 : BAPC 2021 D번 // UKIEPC 2021 D번
*/

int p[3072];
long long mem[3072][3072], cum[3072][3072];

long long big(long long a, long long b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    long long r = -INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < 3072; i++) {
        for (int j = 0; j < 3072; j++) {
            cum[i][j] = -INF;
            mem[i][j] = -INF;
        }
    }
    mem[1][n - 1] = p[1];
    for (int i = 1; i < n; i++) cum[1][i] = p[1];
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            mem[i][j] = cum[i - j][j] + p[i];
        }
        for (int j = n - 1; j > 0; j--) {
            cum[i][j] = big(mem[i][j], cum[i][j + 1]);
        }
    }
    for (int i = 1; i < n; i++) {
        if (mem[n][i] > r) r = mem[n][i];
    }
    printf("%lld", r);
    return 0;
}