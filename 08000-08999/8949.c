#include <stdio.h>

/*
문제 : 주어진 두 자연수 A, B(A, B <= 10^6)를 자릿수 단위로 더한 것을 구한다.

해결 방법 : 두 수를 자릿수 단위로 분해한 다음, 각각 더한다. 그 다음, 앞자리부터 다시 출력하면 된다.

주요 알고리즘 : 수학, 구현

출처 : CHCI 2007RS 1번
*/

int sa[8], sb[8], s[8];

int main(void) {
    int a, b, p = 7;
    scanf("%d %d", &a, &b);
    for (int i = 0; a; i++) {
        sa[i] = a % 10;
        a /= 10;
    }
    for (int i = 0; b; i++) {
        sb[i] = b % 10;
        b /= 10;
    }
    for (int i = 0; i < 8; i++) {
        s[i] = sa[i] + sb[i];
    }
    while (!s[p]) p--;
    while (p >= 0) {
        printf("%d", s[p]);
        p--;
    }
    return 0;
}