#include <stdio.h>

/*
문제 : N(N <= 1000)장의 카드를 섞은 결과를 출력한다. 카드를 두 덩어리로 나누어 앞쪽 덩어리는 홀수번째,
뒤쪽 덩어리는 짝수번째로 각각 넣으면 된다.

해결 방법 : 주어진대로 구현한다.

주요 알고리즘 : 구현

출처 : SEUSA 2013D2 H번
*/

char cards[1024][128];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < (n + 1) >> 1; i++) {
            scanf("%s", cards[i << 1]);
        }
        for (int i = 0; i < n >> 1; i++) {
            scanf("%s", cards[(i << 1) + 1]);
        }
        for (int i = 0; i < n; i++) {
            printf("%s\n", cards[i]);
        }
    }
    return 0;
}