#include <stdio.h>

/*
문제 : N(N <= 10^6)이 주어질 때, N 이하 자연수의 f(x)의 합을 구한다. f(x)는 f의 약수의 합이다.

해결 방법 : 에라토스테네스의 체의 원리를 응용해 1부터 10^6까지 순서대로 해당 수를 약수로 갖는 자연수에 대해
그 수만큼 약수의 값을 높여준다. 이를 반복하면 Nlog(N)의 시간 내로 N 이하의 모든 수에 대한 f(x)를 얻을 수 있다.
합은 간단히 N까지의 누적합을 구하면 된다.

주요 알고리즘 : 수학, 에라토스테네스의 체
*/

int f[1048576];
long long g[1048576];

int main(void) {
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            f[j] += i;
        }
    }
    for (int i = 1; i <= 1000000; i++) {
        g[i] = f[i] + g[i - 1];
    }

    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("%lld\n", g[n]);
    }
    return 0;
}