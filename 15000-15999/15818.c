#include <stdio.h>

/*
문제 : N개의 수들을 곱하고 M으로 나눈 나머지를 구한다. 이 값은 N개의 수를 곱하며 M으로 나눈 나머지를 취하며 풀더라도
같게 나온다.

해결 방법 : 문제에 나온대로 나머지를 취하며 풀면 된다.

주요 알고리즘 : 수학, 구현

출처 : 아주대 2018P A번
*/

int main(void) {
    long long n, m, a, r = 1;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        r *= a;
        r %= m;
    }
    printf("%lld", r);
    return 0;
}