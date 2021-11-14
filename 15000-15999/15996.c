#include <stdio.h>

/*
문제 : N(N < 2^31)!를 A로 최대 몇 번 나눌 수 있는지 구한다.

해결 방법 : N / A부터 A로 나눠가며 0이 될 때 까지 더한 값이 답이다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    long long n, r = 0, a;
    scanf("%lld %lld", &n, &a);
    for (int i = n / a; i; i /= a) r += i;
    printf("%lld", r);
    return 0;
}