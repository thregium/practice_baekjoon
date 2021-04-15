#include <stdio.h>

/*
문제 : 두 수의 비교 결과를 출력한다.

해결 방법 : 두 수의 비교 결과를 출력한다.

주요 알고리즘 : 구현
*/

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%s", a > b ? ">" : a == b ? "==" : "<");
    return 0;
}