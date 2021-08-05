#include <stdio.h>

/*
문제 : 두 자리 수 N을 왼쪽으로 K(K <= 5)번 이동시키며 곱한 수는 몇인지 구한다.

해결 방법 : 1로만 이루어진 길이 (K + 1)의 수를 곱하는 것과 같다.

주요 알고리즘 : 수학, 사칙연산

출처 : CCC 2017J 2번
*/

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 1) n *= 11;
    else if (k == 2) n *= 111;
    else if (k == 3) n *= 1111;
    else if (k == 4) n *= 11111;
    else if (k == 5) n *= 111111;
    printf("%d", n);
    return 0;
}