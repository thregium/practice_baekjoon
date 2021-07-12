#include <stdio.h>

/*
문제 : 주어진 두 수 A, B(A, B <= 10^6)에 대해 두 수의 최소공배수를 구한다.

해결 방법 : 유클리드 호제법을 이용해 두 수의 최대공약수를 구한 뒤 두 수의 곱에서 나누면 된다.

주요 알고리즘 : 수학, 유클리드 호제법

출처 : PLU 2013 A2번
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", (long long)a * b / gcd(a, b));
    }
    return 0;
}