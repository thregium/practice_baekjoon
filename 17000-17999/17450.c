#include <stdio.h>

/*
문제 : 세 과자의 무게와 가격이 주어질 때, 가장 가성비가 좋은 과자를 구한다. 단, 가격은 할인된 가격을 기준으로 한다.
10봉지를 사고, 가격이 5000원 이상인 경우 500원 할인된다.

해결 방법 : 먼저 할인된 가격을 구한 다음, 무게에서 나눈다. 이것이 가성비이므로, 이 값이 가장 큰 것을 고르면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : 서울대 2019D2 A번
*/

int main(void) {
    int sp, sw, np, nw, up, uw;
    double s, n, u;
    scanf("%d %d%d %d%d %d", &sp, &sw, &np, &nw, &up, &uw);
    s = sp * 10;
    if (s >= 5000) s -= 500;
    s /= sw;
    n = np * 10;
    if (n >= 5000) n -= 500;
    n /= nw;
    u = up * 10;
    if (u >= 5000) u -= 500;
    u /= uw;
    if (s < n && s < u) printf("S");
    else if (n < u) printf("N");
    else printf("U");
    return 0;
}