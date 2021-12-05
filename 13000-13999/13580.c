#include <stdio.h>

/*
문제 : 세 자연수 A, B, C(A, B, C <= 1000)가 주어질 때, 하나 이상의 서로 다른 수를 더하거나 빼서 0을 만들 수 있는지 구한다.

해결 방법 : 한 수가 다른 어떤 수와 같거나 어떤 두 수의 합이 나머지 수와 같은 경우 0을 만들 수 있고,
그 외의 경우 0을 만들 수 없다.

주요 알고리즘 : 수학, 사칙연산?

출처 :Brasil 2016 A번
*/

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b || a == c || b == c) printf("S");
    else if (a + b == c || a + c == b || b + c == a) printf("S");
    else printf("N");
    return 0;
}