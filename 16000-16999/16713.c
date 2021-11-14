#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 음이 아닌 정수로 이루어진 수열에서 Q(Q <= 3 * 10^6)개의 쿼리에 응답한다.
[s, e] 사이 모든 값을 XOR한 결과를 구한다.

해결 방법 : 누적 합은 XOR에서도 적용 가능하므로 누적 합을 이용하면 된다. 뺄셈 연산도 XOR로 적용된다.

주요 알고리즘 : 누적 합

출처 : 나코더 2018 G번
*/

int a[1048576];

int main(void) {
    int n, q, s, e, r = 0;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] ^= a[i - 1];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        r ^= (a[e] ^ a[s - 1]);
    }
    printf("%d", r);
    return 0;
}