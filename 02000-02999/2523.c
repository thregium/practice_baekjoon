#include <stdio.h>

/*
문제 : N!(N <= 20000)의 0이 아닌 마지막 숫자를 구한다.

해결 방법 : N 이하에서 5가 가장 많이 곱해진 수 15625는 6회 곱해졌고, 따라서 맨 뒤 7자리만 보더라도 N 범위 내에서는 항상
정확히 답을 구할 수 있다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int n;
    long long r;
    scanf("%d", &n);
    r = 1;
    for (int i = 1; i <= n; i++) {
        r *= i;
        while (r % 10 == 0) r /= 10;
        r %= 100000000;
    }
    printf("%lld\n", r % 10);
    return 0;
}