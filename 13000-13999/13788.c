#include <stdio.h>

/*
문제 : N(N <= 100)명과 만나려고 한다. 각 사람은 시간 단위로 만나며 6시부터 22시 이전까지의
범위 가운데 M(M <= 16)개의 서로 다른 시간 범위에서 만난다. 모든 범위에서 만나는 경우
L(L <= 10^8)만큼의 만족도를 얻을 때, 얻을 수 있는 최대 만족도를 구한다.

해결 방법 : 시각의 개수가 매우 적은 것을 이용해 비트DP를 사용할 수 있다.
이미 사용중인 시간대를 상태로 하여 현재 사람까지 만났(거나 만나지 않았)을 때의 최대 만족도를
저장한 다음, 각 사람마다 모든 상태에 대해 주어진 범위가 전부 사용 가능한 경우
그 사람과 만난 다음 최댓값을 갱신한다. 이를 전부 마친 다음 모든 상태 가운데 최대 만족도를 구하면 된다.

주요 알고리즘 : DP, 비트DP

출처 : JAG 2011P B번
*/

int mem[65536];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, l, s, e, bit, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &m, &l);
            bit = 0;
            for (int j = 0; j < m; j++) {
                scanf("%d %d", &s, &e);
                for (int k = s; k < e; k++) bit |= (1 << (k - 6));
            }
            for (int j = 0; j < 65536; j++) {
                if (!(j & bit)) mem[j | bit] = big(mem[j | bit], mem[j] + l);
            }
        }
        r = 0;
        for (int i = 0; i < 65536; i++) {
            r = big(r, mem[i]);
            mem[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}