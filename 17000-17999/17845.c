#include <stdio.h>

/*
문제 : N(N <= 10000)만큼의 시간이 있고, K(K <= 1000)가지의 과목이 있다. 각 과목의 공부 시간과 중요도가 주어질 때,
주어진 시간 내에 공부를 통해 얻을 수 있는 중요도의 최대치를 구한다. 단, 각 과목은 끝까지 공부해야 중요도를 얻을 수 있다.

해결 방법 : 일반적인 냅색 문제와 같다.

주요 알고리즘 : DP, 냅색

출처 : UNIST 1회 H번
*/

int mem[1024][10240];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, k, im, t, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &im, &t);
        for (int j = 0; j <= n; j++) {
            mem[i][j] = mem[i - 1][j];
            if (j >= t) mem[i][j] = big(mem[i][j], mem[i - 1][j - t] + im);
        }
    }
    for (int i = 0; i <= n; i++) {
        r = big(r, mem[k][i]);
    }
    printf("%d", r);
    return 0;
}