#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^8)이 주어질 때, M!이 N으로 나누어 떨어지는 가장 작은 자연수 M을 구한다.

해결 방법 : N을 소인수분해하면서 N의 소인수마다 그 개수를 구하고,
그 소인수가 그 개수가 되는 최소의 M!을 구하면서 그 중 가장 큰 값을 구하면 된다.

주요 알고리즘 : 수학, 정수론, 소인수분해

출처 : JOISC 06/07 1-2번
*/

int main(void) {
    int n, c, p, r = 1;
    scanf("%d", &n);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            c = 0;
            while (n % i == 0) {
                c++;
                n /= i;
            }
            p = 0;
            for (int j = i; c > 0; j += i) {
                for (int k = j; k % i == 0; c--) k /= i;
                p = j;
            }
            if (p > r) r = p;
        }
    }
    if (n > r) r = n;
    printf("%d", r);
    return 0;
}