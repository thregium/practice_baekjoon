#include <stdio.h>

/*
문제 : A + B = C 형태의 식이 맞는지 검사한다. 단, A, B, C는 한 자리 자연수이다.

해결 방법 : 해당 형태로 식을 입력받은 후 값이 맞는지 구한다.

주요 알고리즘 : 구현, 사칙연산

출처 :PacNW 2016D2 R번
*/

int main(void) {
    int a, b, c;
    scanf("%d + %d = %d", &a, &b, &c);
    if (a + b == c) printf("YES");
    else printf("NO");
    return 0;
}