#include <stdio.h>

/*
문제 : N(N <= 10^9) 이하의 자연수 가운데 K(K <= 20)개의 자연수 중 하나 이상의 자연수로
나누어 떨어지는 수의 개수를 구한다. 각 자연수는 10^9 이하다.

해결 방법 : 포함 배제의 원리에 따르면 홀수개의 수의 공배수는 전부 더하고 짝수개의 수의
공배수는 전부 빼면 원하는 답이 나온다. 공배수는 유클리드 호제법을 이용해 최소 공배수를 구한 후,
N을 그 값으로 나누면 구할 수 있다. 오버플로에 유의한다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법, 포함 배제
*/

long long a[32];

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, k, pcnt;
    long long res = 0, lcm;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < (1 << k); i++) {
        pcnt = 0, lcm = 1;
        for (int j = 0; j < k; j++) {
            if ((i >> j) & 1) {
                pcnt++;
                lcm = (lcm * a[j]) / gcd(lcm, a[j]);
                if (lcm > n) lcm = n + 1;
            }
        }
        if (pcnt & 1) res += n / lcm;
        else res -= n / lcm;
    }
    printf("%lld", res);
    return 0;
}