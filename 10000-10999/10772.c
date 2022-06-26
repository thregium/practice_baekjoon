#include <stdio.h>

/*
문제 : N(N <= 200)개의 조각을 K(K <= N)명에게 나누어 주되 뒤에 나오는 사람에게 돌아가는 조각이
모든 앞에 나오는 사람의 조각보다 많이 돌아가도록 주는 방법의 수를 구한다.

해결 방법 : 수의 분할과 같다. 그 값을 다이나믹 프로그래밍으로 계산하면 된다.

주요 알고리즘 : 수학, 조합론, DP

출처 : CCC 2015 J5번
*/

long long part[256][256];

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) part[i][j] = 1;
            else part[i][j] = part[i - 1][j - 1] + part[i - j][j];
        }
    }
    printf("%lld", part[n][k]);
    return 0;
}