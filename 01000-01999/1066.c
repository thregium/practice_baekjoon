#include <stdio.h>
#define MOD 1000000007

/*
문제 : 0으로 시작하지 않고 각 자릿수가 비내림차순인 N(N <= 1000)자리 자연수 가운데 최대 A(A <= 1000)개의
연속한 등차수열로 분해 가능한 수의 개수를 구한다.

해결 방법 : 수의 길이, A, 마지막 등차, 최근의 수를 각각 변수로 잡고 다이나믹 프로그래밍을 한다.
이때, 등차가 깨진 다음에는 어떤 수든 올 수 있음에 유의해야 한다.

주요 알고리즘 : DP

출처 : SRM 431 D1B
*/

int mem[1024][10][10][10]; //수의 길이, A, 마지막 등차(9면 새로 시작중), 최근의 수

int main(void) {
    int n, a, r = 0;
    scanf("%d %d", &n, &a);
    for (int i = 1; i <= 9; i++) {
        for (int j = i; j <= 9; j++) {
            mem[2][1][j - i][j]++;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 1 + (k == 9 ? 0 : k); l <= 9; l++) {
                    for (int m = l; m <= 9; m++) {
                        if (k == 9) mem[i + 1][j][m - l][m] = (mem[i + 1][j][m - l][m] + mem[i][j][k][l]) % MOD;
                        else if (m == l + k) mem[i + 1][j][k][m] = (mem[i + 1][j][k][m] + mem[i][j][k][l]) % MOD;
                        else mem[i + 1][j + 1][9][m] = (mem[i + 1][j + 1][9][m] + mem[i][j][k][l]) % MOD;
                    }
                }
            }
        }
    }
    if (a > 9 || n == 1) {
        if (a > 9 || a > n) printf("0");
        else printf("9");
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            r = (r + mem[n][a][i][j]) % MOD;
        }
    }
    printf("%d", r);
    return 0;
}