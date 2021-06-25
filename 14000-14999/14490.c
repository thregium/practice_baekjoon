#include <stdio.h>

/*
문제 : 1억 이하의 두 수로 이루어진 비례식이 주어질 때, 이 비례식을 약분한다.

해결 방법 : 유클리드 호제법을 이용해 최대공약수를 구한 뒤, 두 수를 최대공약수로 나누어 준다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법

출처 : 선린 2017 D번
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, m, g;
    scanf("%d:%d", &n, &m);
    g = gcd(n, m);
    printf("%d:%d", n / g, m / g);
    return 0;
}