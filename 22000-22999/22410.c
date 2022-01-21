#include <stdio.h>

/*
문제 : 분수 P / Q(0 < P < Q <= 10^9)가 주어질 때, 이 분수를 유한소수로 나타낼 수 있는
가장 작은 진법을 구한다.

해결 방법 : 우선 분수를 기약분수로 나타낸다. 그러면 그때의 분모를 통해 답을 구해낼 수 있다.
답은 그 분모를 소인수분해 했을 때 나오는 서로 다른 모든 소수의 곱과 같다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법, 소인수분해

출처 : JAG 2015S2 A번
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int p, q, r = 1;
    scanf("%d %d", &p, &q);
    q /= gcd(p, q);
    for (int i = 2; i * i <= q; i++) {
        if (q % i == 0) {
            r *= i;
            while (q % i == 0) q /= i;
        }
    }
    printf("%d", r * q);
    return 0;
}