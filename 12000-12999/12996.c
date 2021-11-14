#include <stdio.h>
#include <string.h>
#define MOD 1000000007

/*
문제 : S(S <= 50)개의 곡을 3명 중 일부(또는 전부)가 작곡한다. 각 사람이 작곡한 곡의 수가 주어질 때,
이렇게 작곡한 곡의 수가 나오도록 할당하는 방법의 수를 구한다.

해결 방법 : S와 3명이 작곡한 곡의 수를 변수로 두고 탑다운 DP를 한다. 모든 경우의 수를 더하면 된다.

주요 알고리즘 : DP
*/

int mem[64][64][64][64];

int dp(int s, int d, int k, int h) {
    int r = 0;
    if (s == 0) {
        if (d == 0 && k == 0 && h == 0) return mem[s][d][k][h] = 1;
        else return mem[s][d][k][h] = 0;
    }
    if (mem[s][d][k][h] >= 0) return mem[s][d][k][h];
    if (d > 0) r = (r + dp(s - 1, d - 1, k, h)) % MOD;
    if (k > 0) r = (r + dp(s - 1, d, k - 1, h)) % MOD;
    if (h > 0) r = (r + dp(s - 1, d, k, h - 1)) % MOD;
    if (d > 0 && k > 0) r = (r + dp(s - 1, d - 1, k - 1, h)) % MOD;
    if (d > 0 && h > 0) r = (r + dp(s - 1, d - 1, k, h - 1)) % MOD;
    if (k > 0 && h > 0) r = (r + dp(s - 1, d, k - 1, h - 1)) % MOD;
    if (d > 0 && k > 0 && h > 0) r = (r + dp(s - 1, d - 1, k - 1, h - 1)) % MOD;
    return mem[s][d][k][h] = r;
}

int main(void) {
    int s, d, k, h;
    scanf("%d %d %d %d", &s, &d, &k, &h);
    memset(mem, -1, 16777216 * sizeof(int));
    printf("%d", dp(s, d, k, h));
    return 0;
}