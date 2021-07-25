#include <stdio.h>
#define INF 1012345678

/*
문제 : B(B <= 10^6)에 가장 가까운 A^N(N <= 9)의 A 값을 구한다.

해결 방법 : N이 몇이든 최대 100만 이하에서 답이 나오기 때문에 A를 1부터 차례로 올라가며 확인하면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : MidC 2006 G번
*/

int main(void) {
    int b, n, x, diff, aa;
    while (1) {
        scanf("%d %d", &b, &n);
        if (b == 0 && n == 0) break;
        diff = INF;
        for (int a = 1;; a++) {
            x = 1;
            for (int i = 0; i < n; i++) x *= a;
            if (x > b) {
                if (x - b < diff) printf("%d\n", a);
                else printf("%d\n", a - 1);
                break;
            }
            else diff = b - x;
        }
    }
    return 0;
}