#include <stdio.h>

/*
문제 : N(N <= 300)의 금액을 C(C <= 8)개의 동전으로 만드는 방법의 수를 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 구할 수 있다. 각 동전과 금액마다 해당 동전까지 확인했을 때의 방법의 수를 저장한다.
이 값은 매번 이전 단계에서 (해당 금액) - (해당 동전의 가치) * (자연수)의 방법의 수의 합과 같다.
동전 0개일 때의 방법의 수는 0원일 때 1가지이고, 나머지 금액일 때는 0가지이다.

주요 알고리즘 : DP, 냅색

출처 : USACO 2009M B4번
*/

long long mem[16][512];

int main(void) {
    int n, c, ci;
    scanf("%d %d", &n, &c);
    mem[0][0] = 1;
    for (int i = 1; i <= c; i++) {
        scanf("%d", &ci);
        for (int j = 0; j <= n; j++) {
            for (int k = j; k >= 0; k -= ci) mem[i][j] += mem[i - 1][k];
        }
    }
    printf("%lld", mem[c][n]);
    return 0;
}