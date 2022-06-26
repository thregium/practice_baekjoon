#include <stdio.h>

/*
문제 : 자연수 X0(X0 <= 10^16)과 N(N <= 50)이 주어질 때, X0에서 1개 이상의 1인 비트를 0으로 바꾸는 작업을
정확히 N회 하여 0으로 바꿀 수 있는 지 구하고, 가능한 경우 인접한 두 수의 차이의 최댓값과
최솟값의 차이를 최소로 하는 과정을 출력한다.

해결 방법 : 맨 앞의 1인 비트를 하나씩 떼어네는 것이 최적임을 알 수 있다. 앞의 1부터 떼어네되
마지막은 0으로 하도록 한다.

주요 알고리즘 : 그리디 알고리즘

출처 : 숭고한 2019 H번
*/

int main(void) {
    long long x, n, c = 0;
    scanf("%lld %lld", &x, &n);
    for (long long i = x; i; i >>= 1) {
        if (i & 1) c++;
    }
    if (c < n) {
        printf("-1");
        return 0;
    }
    for (long long i = (1LL << 60); n > 1; i >>= 1) {
        if (i & x) {
            x -= i;
            printf("%lld ", x);
            n--;
        }
    }
    printf("%lld", 0);
    return 0;
}