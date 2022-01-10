#include <stdio.h>

/*
문제 : 키가 A cm이던 사람이 B cm가 되었다면 몇 cm 자랐는지 구한다. (100 <= A < B <= 200, A, B는 자연수)

해결 방법 : B - A cm 자랐으므로 B - A를 출력하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : JOI 2022예1 3-1번
*/

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", b - a);
    return 0;
}