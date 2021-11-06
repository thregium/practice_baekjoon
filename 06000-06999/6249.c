#include <stdio.h>

/*
문제 : N(N <= 10000)일간 각 날의 환율이 주어질 때, 환율이 떨어지는 날에는 이전 날과의 차이를 출력하고,
최고점을 갱신한 날에는 그 값을 출력한다. 전날의 가격 P와 해당 날 이전의 최고점 H(0 < P, H <= 10000)도 주어진다.
환율이 떨어질 때에는 2 이상씩 떨어진다.

해결 방법 : 매일 환율을 입력받은 다음 전날보다 작으면 전날과의 차이를 출력한다. 최고점보다 높다면
신고점을 갱신한 다음 신고점의 환율을 출력한다. 두 경우의 확인이 끝났다면 전날의 가격을 해당 날의 가격으로 갱신한다.
이를 N일간 반복하면 된다.

주요 알고리즘 : 구현

출처 : Tehran 2012 A번
*/

int main(void) {
    int n, p, h, x;
    scanf("%d %d %d", &n, &p, &h);
    if (h < p) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x < p) {
            printf("NTV: Dollar dropped by %d Oshloobs\n", p - x);
        }
        if (x > h) {
            printf("BBTV: Dollar reached %d Oshloobs, A record!\n", x);
            h = x;
        }
        p = x;
    }
    return 0;
}