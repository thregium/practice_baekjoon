#include <stdio.h>
#include <algorithm>
using namespace std;

/*
문제 : 길이 N(N <= 10)의 순열을 합해 나갈 때, 결과가 F(F <= 10^6)인 순열 가운데 사전 순으로
가장 빠른 순열을 찾는다.

해결 방법 : N이 작기 때문에 모든 가능한 길이 N의 순열에 대해 시도해보면서 처음 나오는 답이 F인
순열을 출력하면 된다.

주요 알고리즘 : 브루트 포스
*/

long long a[16], b[16][16];

long long getres(int n) {
    for (int i = 0; i < n; i++) b[0][i] = a[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) b[i][j] = b[i - 1][j] + b[i - 1][j + 1];
    }
    return b[n - 1][0];
}

int main(void) {
    int n;
    long long f;
    scanf("%d %lld", &n, &f);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    while (1) {
        if (getres(n) == f) {
            for (int i = 0; i < n; i++) printf("%lld ", a[i]);
            return 0;
        }
        next_permutation(a, a + n);
    }
    return 1;
}