#include <stdio.h>

/*
문제 : 파스칼의 삼각형에서 N(N <= 30)행의 K(K <= 30)번째 수를 구한다.

해결 방법 : 파스칼의 삼각형에서 첫 번째 수는 1이고, 아래로 갈 때 마다 위의 두 수를 더해간다는 점을 이용해
DP를 하면 된다.

주요 알고리즘 : DP

출처 : 홍익대 2018 B번
*/

long long mem[32][32];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++) {
        mem[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
        }
    }
    printf("%lld", mem[n - 1][k - 1]);
    return 0;
}