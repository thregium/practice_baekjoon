#include <stdio.h>

/*
문제 : N(N <= 100)개의 코스 가운데 아무거나 하나를 골라 출력한다. 각 코스는 D(D <= 42)개의 요리로 이루어져 있다.

해결 방법 : 첫 번째 코스의 요리를 그대로 출력한다. 다른 코스는 볼 필요조차 없다.

주요 알고리즘 : 구현

출처 : UKIEPC 2020 H번 / BAPC 2020 H번
*/

char buff[32];

int main(void) {
    int n, d;
    scanf("%d%d", &n, &d);
    printf("%d\n", d);
    for (int i = 0; i < d; i++) {
        scanf("%s", buff);
        printf("%s\n", buff);
    }
    return 0;
}