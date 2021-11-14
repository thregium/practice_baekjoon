#include <stdio.h>

/*
문제 : N(N <= 1000)개의 강의가 주어지고, M(M <= 500000)개의 선후관계가 주어질 때, 각 강의는 최소 몇 번째로
들어야 하는지 구한다. 단, 모든 선후관계는 A < B인 경우만 주어진다.

해결 방법 : 모든 선후관계를 확인하면서 낮은 번호부터 차례로 이전의 강의 가운데 가장 답이 높은 강의의 값에
1을 더 높인 수를 답으로 출력하면 된다.

주요 알고리즘 : DP

출처 : 중앙대 2017R G번
*/

int bef[1024][1024], mem[1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, a, b, r;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        bef[b][++bef[b][0]] = a;
    }
    for (int i = 1; i <= n; i++) {
        r = 0;
        for (int j = 1; j <= bef[i][0]; j++) {
            r = big(mem[bef[i][j]], r);
        }
        printf("%d ", r + 1);
        mem[i] = r + 1;
    }
    return 0;
}