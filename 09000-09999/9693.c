#include <stdio.h>

/*
문제 : N(N <= 10^6)!의 마지막에 오는 0의 개수를 구한다.

해결 방법 : N!을 구성하는 5의 개수와 같다.

주요 알고리즘 : 수학, 정수론

출처 : Khawarizmi 2013 A번
*/

int main(void) {
    int n, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0;
        for (int i = n / 5; i; i /= 5) r += i;
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}
