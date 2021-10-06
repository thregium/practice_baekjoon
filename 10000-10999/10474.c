#include <stdio.h>

/*
문제 : 주어진 가분수를 대분수로 바꾼다. 분모와 분자는 모두 2^31보다 작은 자연수이고, 약분은 하지 않는다.

해결 방법 : 자연수 부분은 분자 / 분모의 몫이고, 분자 부분은 분자 / 분모의 나머지이다. 분모는 그대로 두면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : NAQ 2014 F번
*/

int main(void) {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (!b) break;
        printf("%d %d / %d\n", a / b, a % b, b);
    }
    return 0;
}