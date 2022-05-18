#include <stdio.h>

/*
문제 : 힐베르트 곡선의 N(N < 32)단계에서 (x1, y)부터 (x2, y)를 잇는 선분이
힐베르트 곡선과 교차하는 횟수를 구한다.

해결 방법 : 힐베르트 곡선의 구간을 쪼개가면서 최소 수준까지 줄인 다음 그때의 횟수를 모두 더한다.
단, 그대로 하면 시간 초과가 나기 때문에 전체 구간에 대해서는 방향, 크기별로 메모이제이션을 하여
시간을 줄여야 한다.

주요 알고리즘 : DP, 분할 정복

출처 : MidC 2002 B번
*/

const mvd[4][4] = { {1, 3, 0, 0}, {0, 1, 2, 1}, {2, 2, 1, 3}, {3, 0, 3, 2} };
long long mem[64][4];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long crossing(long long n, long long x1, long long x2, long long y, long long d) {
    if (n == 1) {
        if (y == 1) return x2 - x1 - (d == 1 && x1 == 0) - (d == 3 && x2 == 2);
        else return 0;
    }
    long long res = 0;
    if (x1 == 0 && x2 == (1LL << n) && mem[n][d] >= 0) return mem[n][d];
    if (y < (1LL << (n - 1))) {
        if (x1 < (1LL << (n - 1))) {
            res += crossing(n - 1, x1, small(x2, 1LL << (n - 1)), y, mvd[d][0]);
        }
        if (x2 > (1LL << (n - 1))) {
            res += crossing(n - 1, big(x1 - (1LL << (n - 1)), 0), x2 - (1LL << (n - 1)), y, mvd[d][1]);
        }
    }
    else if (y > (1LL << (n - 1))) {
        if (x1 < (1LL << (n - 1))) {
            res += crossing(n - 1, x1, small(x2, 1LL << (n - 1)), y - (1LL << (n - 1)), mvd[d][2]);
        }
        if (x2 > (1LL << (n - 1))) {
            res += crossing(n - 1, big(x1 - (1LL << (n - 1)), 0), x2 - (1LL << (n - 1)),
                y - (1LL << (n - 1)), mvd[d][3]);
        }
    }
    else {
        if (d == 1) {
            res += (x1 <= (1LL << (n - 1)) - 1 && x2 >= (1LL << (n - 1)));
        }
        else if (d == 3) {
            res += (x1 <= (1LL << (n - 1)) && x2 >= (1LL << (n - 1)) + 1);
        }
        else res += ((x1 == 0) + (x2 == (1LL << n)));
    }
    
    if (x1 == 0 && x2 == (1LL << n)) mem[n][d] = res;
    return res;
}

int main(void) {
    long long n, x1, x2, y;
    while (1) {
        scanf("%lld", &n);
        if (n == 0) break;
        for (int i = 0; i < 64; i++) {
            for (int j = 0; j < 4; j++) mem[i][j] = -1;
        }
        scanf("%lld %lld %lld", &x1, &x2, &y);
        printf("%lld\n", crossing(n, x1, x2, (1LL << n) - y, 0));
    }
    return 0;
}