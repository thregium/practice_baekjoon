#include <stdio.h>
#define MOD 1000000

/*
문제 : N(N <= 1000)일동안의 출석부 가운데 개근상을 받을 수 있는 경우를 모두 구한다.
3일 연속 결석 하거나 2회 이상 지각 하지 않으면 개근상을 받을 수 있다.

해결 방법 : 지각한 횟수와 연속으로 결석한 횟수를 변수로 두고 DP를 한다. 경우의 수를 잘 정리해야 한다.

주요 알고리즘 : DP
*/

int mem[1024][6];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    mem[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        mem[i][0] = mem[i - 1][0];
        mem[i][3] = mem[i - 1][3];
        for (int j = 3; j < 6; j++) {
            mem[i][3] = (mem[i][3] + mem[i - 1][j - 3]) % MOD;
        }
        for (int j = 1; j < 3; j++) {
            mem[i][0] = (mem[i][0] + mem[i - 1][j]) % MOD;
            mem[i][j] = (mem[i][j] + mem[i - 1][j - 1]) % MOD;
            mem[i][3] = (mem[i][3] + mem[i - 1][j + 3]) % MOD;
            mem[i][j + 3] = (mem[i][j + 3] + mem[i - 1][j + 2]) % MOD;
        }
    }
    for (int i = 0; i < 6; i++) {
        r = (r + mem[n][i]) % MOD;
    }
    printf("%d", r);
    return 0;
}