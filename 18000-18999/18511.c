#include <stdio.h>

/*
문제 : N(N <= 10^8) 이하의 자연수로 가운데 주어진 K(K <= 3)가지 숫자로만 이루어진 가장 큰 수를 구한다.
항상 이러한 경우가 나오도록 주어진다.

해결 방법 : N부터 1까지의 모든 수를 살피면서 K가지 숫자로 만들 수 있는지 살핀다. 그러한 수가 나오면 출력하고 종료한다.

주요 알고리즘 : 브루트 포스, 수학
*/

int chk[10];

int main(void) {
    int n, k, x;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        chk[x] = 1;
    }
    for (int i = n; i > 0; i--) {
        x = 1;
        for (int j = i; j; j /= 10) {
            if (!chk[j % 10]) {
                x = 0;
                break;
            }
        }
        if (x) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}