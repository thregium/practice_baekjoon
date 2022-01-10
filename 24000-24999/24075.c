#include <stdio.h>

/*
문제 : 두 정수 A, B(-100 <= A, B <= 100)가 주어질 때, A + B와 A - B 중 큰 것을 첫째 줄에, 작은 것을 둘째 줄에 출력한다.

해결 방법 : A + B와 A - B의 값을 구한 후 둘 중 더 큰 것을 찾아 경우를 나누어 두 수를 출력하면 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : JOI 2021예1 3-1번
*/

int main(void) {
    int a, b, apb, amb;
    scanf("%d %d", &a, &b);
    apb = a + b, amb = a - b;
    if (apb < amb) printf("%d\n%d", amb, apb);
    else printf("%d\n%d", apb, amb);
    return 0;
}