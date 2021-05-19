#include <stdio.h>
#define MOD 998244353

/*
문제 : k가 짝수인 경우 S(k) = S(k / 2), 1이 아닌 홀수인 경우 S(k) = S((k - 1) / 2) + S((k + 1) / 2), 1인 경우 S(1) = 1로 정의된 함수가 있다.
이 함수에서 연속된 두 수가 서로소인 경우 그 연속된 두 수의 형태는 수열에서 단 한번만 찾을 수 있다고 한다.
연속된 두 자연수 p, q(p, q <= 400000)가 주어질 때, S(k) = p, S(k + 1) = q가 성립하는 k의 값을 구한다.

해결 방법 : 정의에 따르면 S(x * 2)는 S(x), S(x * 2 + 1)은 S(x) + S(x + 1), S(x * 2 - 1)은 S(x) + S(x - 1)이 된다.
S(k)는 p, S(k + 1)은 q라고 하면 S(2 * k) = p, S(2 * k + 1)은 p + q, S(2 * k + 2)는 q이다.
따라서, 홀수인 k에 대해서 S((k - 1) / 2) = p - q, S((k - 1) / 2 + 1) = q이고, 짝수인 k에 대해 S(k / 2) = p, S(k / 2 + 1) = q - p이므로
이를 통해 재귀적으로 함수를 작성하면 된다.

주요 알고리즘 : 수학, 재귀

출처 : GNY 2020 K번
*/

int solve(int p, int q) {
    if (p == 1 && q == 1) return 1;
    if (p > q) return (solve(p - q, q) * 2 + 1) % MOD;
    else return solve(p, q - p) * 2 % MOD;
}

int main(void) {
    int p, q;
    scanf("%d %d", &p, &q);
    printf("%d", solve(p, q));
    return 0;
}