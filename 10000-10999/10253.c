#include <stdio.h>

/*
문제 : 분수 a / b(1 <= a < b <= 10000, a, b는 자연수)가 주어질 때, 주어진 알고리즘을 이용해 단위분수의 합으로 바꾼다면,
가장 작은 단위분수의 분모를 구한다. 주어진 알고리즘은 a / b 이하의 가장 큰 단위분수를 빼는 것을 반복하는 것이다.

해결 방법 : 문제에 주어진 방식대로 a / b 이하의 가장 큰 단위분수를 빼나가며 단위분수가 될 때 까지 반복하면 된다.
단, 각 과정마다 약분을 해줘야 함에 유의한다. 가장 큰 단위분수의 분모는 ceil(b / a)를 통해 구할 수 있다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법, 시뮬레이션

출처 : Daejeon 2014 D번
*/

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int t;
    long long a, b, g, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld", &a, &b);
        g = gcd(a, b);
        a /= g, b /= g;
        while (a > 1) {
            s = (b + a - 1) / a;
            b *= s, a *= s;
            a -= b / s;
            g = gcd(a, b);
            a /= g, b /= g;
        }
        printf("%lld\n", b);
    }
    return 0;
}