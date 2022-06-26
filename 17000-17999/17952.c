#include <stdio.h>

/*
문제 : N(N <= 10^6)분동안 숙제가 주어지거나 주어지지 않을 때, 주어진 숙제들을 문제에 주어진 방식대로
진행시 얻을 수 있는 점수를 구한다.

해결 방법 : 각 분마다 숙제를 스택에 추가하고, 스택에 숙제가 있다면 맨 위의 숙제를 1분 진행시킨다.
맨 위 숙제가 끝났다면 그 숙제의 점수를 결괏값에 추가하고 그 원소를 스택에서 뺀다.
이렇게 계속 진행하여 최종 점수를 출력하면 된다.

주요 알고리즘 : 자료 구조, 스택, 시뮬레이션

출처 : 한양대 6회 AA/BA번
*/

int homework[1048576][2];
int hcnt = 0;

int main(void) {
    int n, o, a, t, score = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &o);
        if (o) {
            scanf("%d %d", &a, &t);
            homework[hcnt][0] = a;
            homework[hcnt][1] = t;
            hcnt++;
        }
        if (hcnt == 0) continue;
        homework[hcnt - 1][1]--;
        if (homework[hcnt - 1][1] == 0) {
            score += homework[hcnt - 1][0];
            hcnt--;
        }
    }
    printf("%d", score);
    return 0;
}