#include <stdio.h>

/*
문제 : N(N <= 200)장의 카드가 있고, S(S <= N - 1)번의 과정 후 P번 카드만 남도록 하려고 한다.
매 과정마다 M(1 < M < 남은 카드 수)장의 카드를 고르고, 해당 카드들만 남기거나 해당 카드가 아닌 것들만 남기는 것을 반복한다.
각 과정에서 고르는 카드들이 주어지면 해당 카드들을 남길 지 제거할 지 여부를 출력한다.

해결 방법 : 고른 카드들 중 P번 카드가 있다면 남겨야 하고 없다면 제거해야 한다.

주요 알고리즘 : 구현

출처 : Rocky 2020 D번
*/

int main(void) {
    int n, p, s, m, c, r;
    scanf("%d %d %d", &n, &p, &s);
    for (int i = 0; i < s; i++) {
        r = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &c);
            if (c == p) r = 1;
        }
        if (r) printf("KEEP\n");
        else printf("REMOVE\n");
    }
    return 0;
}