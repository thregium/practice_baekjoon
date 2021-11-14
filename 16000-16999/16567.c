#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 이진수가 주어진다. M(M <= 10^6)개의 쿼리에 응답한다.
0. 인접한 1의 덩어리가 몇 개 있는지 구한다.
1. x번째 비트를 1로 바꾼다.

해결 방법 : 먼저 1의 덩어리의 개수를 저장하고 있는다. 0번 쿼리가 들어오면 그 값을 출력한다.
1번 쿼리가 들어오면 양 옆 값과 비교해서 둘 다 1인 경우 답에서 1을 빼고, 둘 다 0인 경우 1을 더한다. 둘 다 아니라면 그대로 둔다.
단, 이미 1인 비트라면 아무것도 하지 않고 넘어가야 한다.

주요 알고리즘 : 구현?

출처 : 서강대 2018C A번
*/

int bin[1048576];

int main(void) {
    int n, m, o, p, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &bin[i]);
        if (bin[i] == 1 && bin[i - 1] == 0) r++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &o);
        if (o == 0) {
            printf("%d\n", r);
        }
        else {
            scanf("%d", &p);
            if (bin[p]) continue;
            r -= bin[p - 1] + bin[p + 1] - 1;
            bin[p] = 1;
        }
    }
    return 0;
}