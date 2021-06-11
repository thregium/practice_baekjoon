#include <stdio.h>

/*
문제 : 입금액 K가 주어지면 수수료를 구한다. 수수료는 기본액 25$에 입금액의 1%를 더한 것이고,
최소 100$, 최대 2000$이다.

해결 방법 : 수수료를 구한 다음 범위에서 벗어난 경우 범위의 끝값으로 바꾸면 된다.

주요 알고리즘 : 구현

출처 : ROI Team 2020 A번
*/

int main(void) {
    int k;
    double com;
    scanf("%d", &k);
    com = 25 + k / 100.0;
    if (com < 100) com = 100;
    else if (com > 2000) com = 2000;
    printf("%lf", com);
    return 0;
}