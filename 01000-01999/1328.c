#include <stdio.h>
#define MOD 1000000007

/*
문제 : 길이 N(N <= 100)의 1 ~ N으로 이루어진 순열이 있다. 이 순열을 왼쪽에서부터 보았을 때 증가하는 수는 L개이고,
오른쪽에서부터 보았을 때 증가하는 수는 R개라고 했을 때, N, L, R이 주어지면 해당하는 순열의 개수를 구한다.

해결 방법 : 각각의 N, L, R마다 가장 큰 수를 모든 위치에 놓아본다. 그러면 그 위치에 놓았을 때 나오는 순열의 개수는
(왼쪽과 오른쪽 순열의 가짓수의 곱) * (N - 1까지의 수를 두 부분으로 나누는 방법의 가짓수)와 같다.
먼저, 각 순열의 가짓수는 각 부분 순열의 수의 개수에 각 방향에서 보았을 때의 증가하는 수가 L - 1 또는 R - 1인 순열의 수와 같다.
여기서 반대 방향은 볼 필요가 없으므로 각 방향에 따른 합을 미리 구해놓는다.
나누는 방법의 가짓수는 (N - 1)C(왼쪽 수의 개수) 와 같다. N이 100 이하이므로 이 역시 미리 구해놓으면 된다.
이제 다이나믹 프로그래밍을 통해 위 점화식을 풀면 답을 얻을 수 있다.

주요 알고리즘 : DP, 조합론
*/

int mem[128][128][128], lsum[128][128], rsum[128][128], comb[128][128];

int main(void) {
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    comb[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= 100; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }
    mem[1][1][1] = 1;
    lsum[0][0] = 1;
    rsum[0][0] = 1;
    lsum[1][1] = 1;
    rsum[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int li = 1; li <= i; li++) {
            for (int ri = 1; ri <= i; ri++) {
                for (int j = 0; j < i; j++) {
                    mem[i][li][ri] = (mem[i][li][ri] + (long long)lsum[j][li - 1] * rsum[i - j - 1][ri - 1] % MOD * comb[i - 1][j]) % MOD;
                }
            }
        }
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                lsum[i][j] = (lsum[i][j] + mem[i][j][k]) % MOD;
                rsum[i][k] = (rsum[i][k] + mem[i][j][k]) % MOD;
            }
        }
    }
    printf("%d", mem[n][l][r]);
    return 0;
}