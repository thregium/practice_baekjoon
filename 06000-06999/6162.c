#include <stdio.h>

/*
문제 : 예상 강수량 E와 실제 강수량 A(0 <= E, A <= 10^6, A != 0)가 주어질 때, 어느 정도 가뭄인지 구한다.
A가 E 이상인 경우 가뭄이 아니고(no drought), E가 A의 5배 이하라면 일반 가뭄(drought), 25배 이하라면 메가 가뭄(mega drought),
125배 이하라면 mega mega drought, ... 이런 식으로 늘어난다.

해결 방법 : 두 값을 입력받은 다음, A와 E를 먼저 비교한다 A가 E 이상인 경우 가뭄이 아니다.
그 이후로는 A를 5배씩 늘려가며 A가 E 이상이 되지 않는 경우 mega를 하나씩 늘려간다.
A가 E 이상이 되는 순간 drought를 출력하면 된다.

주요 알고리즘 : 수학

출처 : USC 2014F A번
*/

int main(void) {
    int t, e, a;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &e, &a);
        printf("Data Set %d:\n", tt);
        if (a >= e) {
            printf("no drought\n\n");
            continue;
        }
        while (1) {
            a *= 5;
            if (a >= e) break;
            printf("mega ");
        }
        printf("drought\n\n");
    }
    return 0;
}