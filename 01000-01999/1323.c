#include <stdio.h>

/*
문제 : 10^9 이하의 자연수 N과 100000 이하의 자연수 K가 주어질 때, N을 몇 번 나열해야 K로 나누어 떨어지는지 여부를 구한다.
아무리 나열하더라도 나누어 떨어지지 않는다면 -1을 출력한다.

해결 방법 : K로 나누어 떨어지는지 여부만 알면 되기 때문에 K로 나눈 나머지만 들고 있더라도 답을 구하는 데에는 지장이 없다.
N을 한번 붙이는 것은 자릿수만큼을 곱한 다음 N을 더하는 것과 같다. 이때마다 0이 되는 지 확인하고
그러하다면 그 때 까지 붙인 횟수를 출력하면 된다. 또한, 비둘기집 원리에 의해 적어도 K번 이후에는 같은 나머지가 반복되므로
K번까지 나누어 떨어지지 않는다면 -1을 출력하면 된다.

주요 알고리즘 : 수학, 정수론

출처 : SRM 390 D1A / D2B
*/

long long getm(long long n) {
    if (n < 10) return 10;
    else if (n < 100) return 100;
    else if (n < 1000) return 1000;
    else if (n < 10000) return 10000;
    else if (n < 100000) return 100000;
    else if (n < 1000000) return 1000000;
    else if (n < 10000000) return 10000000;
    else if (n < 100000000) return 100000000;
    else if (n < 1000000000) return 1000000000;
    else return 10000000000;
}

int main(void) {
    long long n, m, k, x;
    scanf("%lld %lld", &n, &k);
    m = getm(n);
    x = n % k;
    for (int i = 1; i <= k; i++) {
        if (x == 0) {
            printf("%d", i);
            return 0;
        }
        x = (x * m + n) % k;
    }
    printf("-1");
    return 0;
}