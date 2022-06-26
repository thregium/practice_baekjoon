#include <stdio.h>

/*
문제 : 구간 [L, R](1 <= L <= R <= 10^9)에서 N(N <= 18)개의 자연수(<= 10^9) 중 적어도 하나로
나누어 떨어지는 자연수의 개수를 구한다.

해결 방법 : 포함 배제의 원리를 이용하여 홀수 가지 원소로 나누어지는 수의 개수 합 - 짝수 가지
원소로 나누어지는 수의 개수 합을 구하면 된다. 이 과정에서 각 집합으로 나누어지는 수의 개수는
유클리드 호제법으로 최소공배수를 구하는 방식을 통해 찾으면 된다. 단, 오버플로가 일어나지 않도록 주의한다.

주요 알고리즘 : 수학, 유클리드 호제법, 포함 배제
*/

long long a[32];

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, l, r, pcnt;
    long long res = 0, lcm;
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < (1 << n); i++) {
        pcnt = 0, lcm = 1;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                pcnt++;
                lcm = (lcm * a[j]) / gcd(lcm, a[j]);
                if (lcm > r) lcm = r + 1;
            }
        }
        if (pcnt & 1) res += r / lcm - (l - 1) / lcm;
        else res -= r / lcm - (l - 1) / lcm;
    }
    printf("%lld", res);
    return 0;
}