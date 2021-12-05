#include <stdio.h>
#include <stdlib.h>

/*
문제 : 수직선상의 위치 S(1 <= S <= 10^9)에서 N(N <= 100000)개의 자연수(<= 10^9) 위치로 모두 이동할 수 있는
가장 작은 이동 단위를 구한다.

해결 방법 : 유클리드 호제법을 이용하여 S와 모든 자연수와의 거리간의 gcd를 구하면 된다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, s, a, g = 0;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (g == 0) g = abs(s - a);
        else g = gcd(g, abs(s - a));
    }
    if (g == 0) return 1;
    printf("%d", g);
    return 0;
}