#include <stdio.h>

/*
문제 : 길이 N(N <= 10^12)의 1 ~ N으로 이루어진 순열에서 i번째 수 중 하나라도 i가 될 확률을 구한다.

해결 방법 : 이 값을 직접 구해보면 빠르게 수렴하는 것을 알 수 있다. 따라서, 작은 수에 대해서 미리 값을 구해둔 후
그 이상의 값은 구해둔 마지막 값으로 출력하면 된다.

주요 알고리즘 : 수학, 조합론, 전처리

출처 : UKIEPC 2016 L번
*/

long long fact[16];
double mem[16];

int main(void) {
    long long n;
    scanf("%lld", &n);
    fact[0] = 1;
    mem[0] = 0.0;
    for (int i = 1; i < 16; i++) fact[i] = fact[i - 1] * i;
    for (int i = 1; i < 16; i++) mem[i] = mem[i - 1] + 1.0 / fact[i] * ((i & 1) ? 1 : -1);
    if (n > 15) printf("%.9f", mem[15]);
    else printf("%.9f", mem[n]);
    return 0;
}