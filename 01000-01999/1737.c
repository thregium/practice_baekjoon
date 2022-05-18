#include <stdio.h>
#include <string.h>
#include <math.h>
#define MOD 1000000000000000000
#define PI acos(-1)

/*
문제 : 자연수 N(N <= 1000)이 주어질 때, p(n) = p(n - 1) + p(n - pi) (n > pi), p(n) = 1(n <= pi)로
정의된 함수의 p(n) 값을 구한다.

해결 방법 : [빠지는 1의 개수][빠지는 파이의 개수]로 2차원 DP를 하면 된다. 실수 오차에 유의한다.

주요 알고리즘 : DP

출처 : IPSC 2001 F번
*/

long long mem[1024][384];

long long dp(int n, int o, int p) {
    if (n - o - p * PI < -0.00000001) return 0;
    else if (n - o - p * PI <= PI + 0.000000001) return 1;
    if (mem[o][p] >= 0) return mem[o][p];
    else return mem[o][p] = (dp(n, o + 1, p) + dp(n, o, p + 1)) % MOD;
}

int main(void) {
    int n;
    memset(mem, -1, sizeof(mem));
    scanf("%d", &n);
    printf("%lld", dp(n, 0, 0));
    return 0;
}