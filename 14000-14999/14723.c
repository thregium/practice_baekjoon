#include <stdio.h>

/*
문제 : N(N <= 1000)번째 분수가 몇번째 분수인지 구한다.

해결 방법 : 분모와 분자의 합을 미리 확인한 후, 그 중 몇 번째인지 구하면 된다.

주요 알고리즘 : 수학

출처 : 충남대 1회 H번
*/

int main(void) {
    int x, i, a, b, s = 0;
    scanf("%d", &x);
    for (i = 0; i < x; s++) i += s;
    a = i - x + 1;
    b = s - (i - x + 1);
    printf("%d %d", a, b);
    return 0;
}