#include <stdio.h>

/*
문제 : 세 개의 0 또는 1이 주어질 때, 다른 하나를 구한다. 없으면 *를 출력한다.

해결 방법 : 셋 중 하나가 나머지와 다르다면 그것을 출력하고, 그러한 것이 없다면 *를 출력하면 된다.

주요 알고리즘 : 구현

출처 : Brasil 2013 A번
*/

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a != b && a != c) printf("A");
    else if (b != a && b != c) printf("B");
    else if (c != a && c != b) printf("C");
    else printf("*");
    return 0;
}