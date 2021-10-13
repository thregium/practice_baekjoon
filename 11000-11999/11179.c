#include <stdio.h>
#include <stdlib.h>

/*
문제 : 자연수 N(N <= 10^9)이 주어질 때, N을 2진수로 나타낸 다음 뒤집어서 나타낸 수를 10진수로 변환한 것의 값을 구한다.

해결 방법 : 해당 수를 뒷자리부터 2진수 문자열로 나타낸 후, strtoll 함수를 이용하여 10진수로 변환하면 된다.

주요 알고리즘 : 수학, 문자열

출처 : KTH 2011 A번
*/

char b2[128];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; n; i++) {
        b2[i] = (n & 1) + '0';
        n >>= 1;
    }
    printf("%lld", strtoll(b2, NULL, 2));
    return 0;
}