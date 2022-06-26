#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678
#define INF2 12345678987654321

/*
문제 : N(N <= 1000)명의 고객이 차례로 오고, 각 고객은 P(P <= 100)개의 물건을 가져온다.
각 물건에는 고유의 목표 압력(<= 10^9, 자연수)이 있다. 각 고객이 가져온 물건들의 순서를 최적으로 조절하여
모든 물건의 압력을 맞추는 데 걸리는 압력 이동 횟수의 최솟값을 구한다. 압력은 초기에 0이며
1회 이동시 1 단위로 올리거나 내릴 수 있다.

해결 방법 : 각 고객의 시작 물건과 끝 물건에 따라 그때의 압력 이동 범위는 (최댓값 - 최솟값) * 2에서
|시작 압력 - 끝 압력|을 뺀 것과 같다. 이를 이용해 각 고객의 끝난 물건을 상태로 하여
다이나믹 프로그래밍을 하면 각 고객의 끝난 물건마다의 압력 이동 횟수를 구할 수 있고,
마지막 고객의 압력 이동 횟수 가운데 최솟값을 고르면 답이 된다.

주요 알고리즘 : DP, 그리디 알고리즘

출처 : GCJ 2022B B번
*/

int prod[1024][128];
long long mem[1024][128];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int t, n, p, hi, lo;
    long long res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p; i++) mem[0][i] = INF2;
        mem[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            hi = 0, lo = INF;
            for (int j = 0; j < p; j++) {
                scanf("%d", &prod[i][j]);
                if (prod[i][j] > hi) hi = prod[i][j];
                if (prod[i][j] < lo) lo = prod[i][j];
            }

            for (int j = 0; j < p; j++) {
                mem[i][j] = INF2;
                for (int k = 0; k < p; k++) {
                    mem[i][j] = small(mem[i][j], mem[i - 1][k] +
                        small(hi - lo + llabs(prod[i - 1][k] - lo) + llabs(prod[i][j] - hi),
                        hi - lo + llabs(prod[i - 1][k] - hi) + llabs(prod[i][j] - lo)));
                }
            }
        }

        res = INF2;
        for (int i = 0; i < p; i++) {
            if (mem[n][i] < res) res = mem[n][i];
        }
        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}