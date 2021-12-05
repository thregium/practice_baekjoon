#include <stdio.h>

/*
문제 : 32767 이하의 두 자연수가 주어질 때, 문제에 주어진 유클리드 호제법 알고리즘을 이용하여 최대공약수를 구한다.

해결 방법 : 유클리드 호제법을 이용한다.

주요 알고리즘 : 수학, 유클리드 호제법, 구현

출처 : NOIS 2006 1번
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}