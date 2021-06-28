#include <stdio.h>

/*
문제 : 양념치킨과 후라이드 치킨, 반반치킨을 사는 가격을 각각 A, B, C원이라고 했을 때, 양념치킨 X인분과 후라이드 Y인분 이상을
사는데 드는 최소 비용을 구한다. 반반치킨 2인분을 사서 1인분씩으로 하는 것도 가능하다.

해결 방법 : 반반치킨만 사는 경우와, 반반치킨을 사고 나머지를 후라이드 또는 양념으로 사는 경우, 양념과 후라이드만 사는 경우로
나눈 다음, 가장 싼 것을 고른다.

주요 알고리즘 : 수학, 케이스 워크
*/

int main(void) {
    int a, b, c, x, y, p1, p2, p3;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    if (x < y) {
        p1 = c * y * 2;
        p2 = c * x * 2 + b * (y - x);
        p3 = a * x + b * y;
    }
    else {
        p1 = c * x * 2;
        p2 = c * y * 2 + a * (x - y);
        p3 = a * x + b * y;
    }
    if (p1 < p2 && p1 < p3) printf("%d", p1);
    else if (p2 < p1 && p2 < p3) printf("%d", p2);
    else printf("%d", p3);
    return 0;
}