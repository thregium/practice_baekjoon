#include <stdio.h>

/*
문제 : N(N <= 10^9) 이상의 가장 작은 하샤드 수를 구한다. 하샤드 수는 모든 자릿수의 합으로 나누어 떨어지는 수이다.

해결 방법 : 자릿수의 합이 크지 않기 때문에 대부분의 경우 하샤드 수가 금방 나오게 된다.
따라서, i 이상의 수에 대해 브루트 포스로 확인해 보면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : EastC 2018 PB번
*/

int main(void) {
    int n, d;
    scanf("%d", &n);
    for (int i = n;; i++) {
        d = 0;
        for (int x = i; x; x /= 10) d += x % 10;
        if (i % d == 0) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}