#include <stdio.h>

/*
문제 : N(N <= 500)에서 시작하는 헤일스톤 수열에서 1이 나오기 전까지 가장 큰 수를 구한다.

해결 방법 : 헤일스톤 수열을 만들어가며 가장 큰 수를 찾으면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Latin 2011 PB번
*/

int main(void) {
    int t, n, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = n;
        while (n > 1) {
            if (n > r) r = n;
            if (n & 1) n = n * 3 + 1;
            else n >>= 1;
        }
        printf("%d\n", r);
    }
    return 0;
}