#include <stdio.h>

/*
문제 : 10^10000 이하의 두 수 A, B가 있다고 할 때 모든 (자릿수 조합의 곱)의 합을 구한다.

해결 방법 : 각 자릿수는 상대 수의 모든 자릿수에 곱해지므로 각 자릿수마다 결과에 추가되는 값은
상대 수의 모든 자릿수의 합과 같다. 따라서, 두 수의 자릿수의 합의 곱을 구하면 결과를 구할 수 있다.

주요 알고리즘 : 문자열, 수학

출처 : USACO 2008/02 B3번
*/

char a[10240], b[10240];

int main(void) {
    long long ax = 0, bx = 0;
    scanf("%s %s", a, b);
    for (int i = 0; a[i]; i++) {
        ax += a[i] - '0';
    }
    for (int i = 0; b[i]; i++) {
        bx += b[i] - '0';
    }
    printf("%lld", ax * bx);
    return 0;
}