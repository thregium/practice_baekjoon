#include <stdio.h>

/*
문제 : N(N <= 10000)개의 음표로 이루어진 악보가 주어진다. 각 악보는 B_i(B_i <= 120)의 시간동안 연주된다.
이때, Q(Q <= 50000)개의 쿼리에 응답한다.
T_i(T_i <= 12 * 10^5) 시각에 어떤 음표를 연주하고 있는지 구한다.
첫 음은 0에 시작하고 각 음표는 B_i 시간이 끝나기 직전에 끝난다.

해결 방법 : 길어야 1200000 내에 곡이 끝나므로 모든 곡의 시각에 대해 연주 중인 음표를 미리 구해 놓은 다음,
T_i가 들어올 때 마다 그때의 음표를 찾아서 구하면 된다.

주요 알고리즘 : 구현

출처 : USACO 2009D B3번
*/

int timing[1310720];

int main(void) {
    int n, q, t, x = 0;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        for (int j = x; j < x + t; j++) {
            timing[j] = i + 1;
        }
        x += t;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        printf("%d\n", timing[x]);
    }
    return 0;
}