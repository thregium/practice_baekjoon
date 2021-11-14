#include <stdio.h>

/*
문제 : N(N <= 50000)개의 수가 있다. 연속한 K(K <= N / 3)개 수로 이루어진 구간 3개의 합이 가장 크도록 할 때,
그 합을 구한다. 각 구간은 겹쳐서는 안 된다.

해결 방법 : 각 수마다의 누적 합을 미리 구해놓는다. 그 다음, 각 수마다 K개 뒤까지의 수들을 더하면 몇이 되는지
합한 구간의 개수마다 DP를 하면 된다. 이때, 이전 수가 더 큰 경우에는 그 값으로 미리 업데이트를 해 줘야 한다.

주요 알고리즘 : DP, 누적 합

출처 : 정올 2003 초3번 // IIPC 2005 G번
*/

int a[51200], mem[51200][4];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    scanf("%d", &k);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            if (i > 0) mem[i][j] = big(mem[i][j], mem[i - 1][j]);
        }
        for (int j = 0; j < 3; j++) {
            mem[small(n, i + k)][j + 1] = big(mem[small(n, i + k)][j + 1], mem[i][j] + a[small(n, i + k)] - a[i]);
        }
    }
    printf("%d", mem[n][3]);
    return 0;
}