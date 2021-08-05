#include <stdio.h>

/*
문제 : 통화와 데이터 사용량이 각각 주어질 때, 3가지 요금제 중 가장 싼 요금제를 선택했을 때의 요금을 구한다.

해결 방법 : 3가지 요금제의 요금을 계산한 다음 가장 싼 것을 고르면 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : Tehran 2017 A번
*/

int main(void) {
    int c, d, x, y, z;
    while (1) {
        scanf("%d %d", &c, &d);
        if (c == 0 && d == 0) break;
        x = c * 30 + d * 40;
        y = c * 35 + d * 30;
        z = c * 40 + d * 20;
        if (x <= y && x <= z) printf("%d\n", x);
        else if (y <= x && y <= z) printf("%d\n", y);
        else printf("%d\n", z);
    }
    return 0;
}