#include <stdio.h>

/*
문제 : 합해서 2^N(N <= 62)이 되는 두 자연수 A, B가 주어질 때, N을 A와 B로 정확히 나누려면 절반으로 나누는 것을
최대 몇 회 해야 하는지 구한다. 단, 합하는 연산은 몇번이든 할 수 있다.

해결 방법 : N을 A와 B의 최소 단위가 되는 2^X까지 나누어야 한다. 여기서 1 단위까지 나누면 N회 나누는 것이므로
N에서 A나 B를 2로 나눌 수 있는 횟수를 뺀 것이 답이 된다.

주요 알고리즘 : 수학

출처 : GCPC 2014 F번
*/

int main(void) {
    int t, n;
    long long a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %lld %lld", &n, &a, &b);
        while (~a & 1) {
            a >>= 1;
            n--;
        }
        printf("%d\n", n);
    }
    return 0;
}