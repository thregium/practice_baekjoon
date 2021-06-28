#include <stdio.h>

/*
문제 : 한 변의 길이가 A인 정삼각형을 길이가 B인 정삼각형으로 덮으려고 할 때, 필요한 정삼각형의 수를 구한다.
단, A % B = 0이다.

해결 방법 : 작은 정삼각형의 면적은 큰 정삼각형의 (B / A)^2 배이다. 따라서, 필요한 정삼각형의 수는 (A / B)^2배가 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : CCPC 2015D2 B번
*/

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", (a / b) * (a / b));
    }
    return 0;
}