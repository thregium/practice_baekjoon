#include <stdio.h>

/*
문제 : 직사각형의 너비 W와 높이 H(W, H <= 10^6)가 주어질 때, 해당 직사각형을 빈 공간 없이 정사각형으로
채우기 위해 필요한 정사각형의 최소 개수를 구한다. 정사각형의 크기는 원하는 대로 할 수 있다.

해결 방법 : 정사각형의 한 변의 길이가 너비와 높이의 최대공약수인 경우가 채울 수 있는 정사각형의 최대 크기이고,
필요한 정사각형을 최소로 할 수 있는 크기이다. 최대공약수를 구한 후, 넓이에서 최대공약수의 제곱을 나누면 된다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법

출처 : Arab 2009 B번
*/

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    long long w, h;
    while (1) {
        scanf("%lld %lld", &w, &h);
        if (w == 0) break;
        printf("%lld\n", w * h / (gcd(w, h) * gcd(w, h)));
    }
    return 0;
}