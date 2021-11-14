#include <stdio.h>

/*
문제 : 자연수 N(N < 1000)이 주어질 때, (1, 1)에서 (N, N)까지 두 수 가운데 하나를 1씩 올리면서
두 수를 이어붙인 수가 소수인 경우가 가장 많도록 할 때 나오는 소수의 수를 구한다. 단, 11은 제외한다.

해결 방법 : 에라토스테네스의 체를 이용하여 10^6 이하의 소수들을 구하고, (N, N)부터 탑다운 방식으로 DP를 진행하면 된다.

주요 알고리즘 : DP, 수학, 에라토스테네스

출처 : BtOI 2011 P2번
*/

char sieve[1048576];
int mem[1024][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int putting(int a, int b) {
    if (b < 10) return a * 10 + b;
    else if (b < 100) return a * 100 + b;
    else if (b < 1000) return a * 1000 + b;
    else return a * 10000 + b;
}

int dp(int x, int y) {
    if (mem[x][y] >= 0) return mem[x][y];
    else if (x == 1 && y == 1) return mem[x][y] = 0;
    int r = 0;
    if (x > 1) r = big(r, dp(x - 1, y));
    if (y > 1) r = big(r, dp(x, y - 1));
    return mem[x][y] = r + (!sieve[putting(x, y)]);
}

int main(void) {
    int n;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) mem[i][j] = -1;
    }
    scanf("%d", &n);
    printf("%d", dp(n, n));
    return 0;
}