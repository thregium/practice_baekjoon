#include <stdio.h>

/*
문제 : 수입을 통해 얻을 수 있는 이익이 주어질 때, 세금을 뗀 다음 남는 이익을 구한다. 100만 초과 500만 이하인 경우 세율은 10%,
500만 초과인 경우 세율은 20%이고, 이익은 1000만 이하의 1000의 배수이다.

해결 방법 : 이익을 구간별로 나누어 남은 이익을 계산하면 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : Tehran Site 2016 A번
*/

int main(void) {
    int x;
    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        if (x <= 1000000) printf("%d\n", x);
        else if (x <= 5000000) printf("%d\n", x * 9 / 10);
        else printf("%d\n", x * 8 / 10);
    }
    return 0;
}
