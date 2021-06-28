#include <stdio.h>
#include <string.h>

/*
문제 : A에 B를 C회 XOR한 결과를 구한다. 단, C는 10^100 이하의 자연수이다.

해결 방법 : C가 매우 크기 때문에 문자열로 받는다. C의 홀짝 여부만 보면 되므로 C의 마지막 자리가 홀수인지 짝수인지 보면 된다.
C가 짝수이면 A 그대로인 것과 같고, 홀수이면 A ^ B와 같다.

주요 알고리즘 : 수학, 문자열

출처 : 인하대 2017 C번
*/

char c[128];

int main(void) {
    int a, b, x;
    scanf("%d %d %s", &a, &b, c);
    x = c[strlen(c) - 1] - '0';
    if (x & 1) printf("%d", a ^ b);
    else printf("%d", a);
    return 0;
}