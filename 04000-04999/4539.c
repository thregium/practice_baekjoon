#include <stdio.h>

/*
문제 : N(N < 10^8)이 주어질 때, 뒷 자리부터 차례로 반올림해 나온 결과를 구한다.

해결 방법 : 일의 자리(자릿수 10)에서 시작해 자릿수를 10배로 올려가며 N보다 작을 동안 반복한다.
자릿수로 나눈 나머지가 자릿수의 절반 이상이라면 올림하고 미만이라면 내림하면 된다.

주요 알고리즘 : 수학

출처 : SCUSA 2006 1번
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 10; n > i; i *= 10) {
            if (n % i >= i / 2) n += i - n % i;
            else n -= n % i;
        }
        printf("%d\n", n);
    }
    return 0;
}