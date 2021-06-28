#include <stdio.h>

/*
문제 : 사칙연산의 우선순위가 없다고 가정할 때, 연산자 2개인 식을 오른쪽부터 계산한 결과와 왼쪽부터 계산한 결과 중
작은 것부터 차례대로 출력한다.

해결 방법 : 경우를 나누어 직접 두가지 경우를 계산한 후 작은 것을 먼저, 큰 것을 다음에 출력하면 된다.

주요 알고리즘 : 구현, 케이스 워크

출처 : 충남대 2회 A번
*/

int main(void) {
    int k1, k2, k3, a, b;
    char o1, o2;
    scanf("%d %c %d %c %d", &k1, &o1, &k2, &o2, &k3);
    if (o1 == '+') a = k1 + k2;
    else if (o1 == '-') a = k1 - k2;
    else if (o1 == '*') a = k1 * k2;
    else a = k1 / k2;
    if (o2 == '+') a = a + k3;
    else if (o2 == '-') a = a - k3;
    else if (o2 == '*') a = a * k3;
    else a = a / k3;

    if (o2 == '+') b = k2 + k3;
    else if (o2 == '-') b = k2 - k3;
    else if (o2 == '*') b = k2 * k3;
    else b = k2 / k3;
    if (o1 == '+') b = b + k1;
    else if (o1 == '-') b = k1 - b;
    else if (o1 == '*') b = b * k1;
    else b = k1 / b;

    if (a < b) printf("%d\n%d", a, b);
    else printf("%d\n%d", b, a);
    return 0;
}