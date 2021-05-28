#include <stdio.h>

/*
문제 : A와 B 사이의 수들의 개수와 그 수들을 전부 구한다.(A, B <= 10^15)(|A - B| <= 100000)

해결 방법 : A가 B보다 큰 경우 두 수를 바꿔준다. 그 다음으로 두 수 사이 수들의 개수를 구한다.
A와 B의 차가 1 이하라면 0이고, 그 외에는 A와 B의 차 - 1이다. 각 수들은 A + 1부터 B - 1까지 계속 돌며 출력하면 된다.

주요 알고리즘 : 구현

출처 : BOI 2014 P1번
*/

void swap(long long* a, long long* b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a > b) swap(&a, &b);
    if (b < a + 2) printf("0\n");
    else printf("%lld\n", b - a - 1);
    for (long long i = a + 1; i < b; i++) {
        printf("%lld ", i);
    }
    return 0;
}