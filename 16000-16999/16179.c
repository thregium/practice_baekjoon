#include <stdio.h>
#define MOD 9973

/*
문제 : 맨 앞 두 자리의 합이 짝수이거나 맨 뒤 두 자리가 소수인 0으로 시작하지 않는 N(4 <= N <= 100)자리
자연수의 개수를 구한다.

해결 방법 : N = 4일 때가 예제에 나와있다. N이 거기서 1씩 올라갈 때 마다 답은 10배씩 늘어난다.
여기서 각각 모듈로를 해 나가면 답이 된다.

주요 알고리즘 : 수학, 조합론

출처 : INC 2009 E번
*/

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 5625;
        for (int i = 4; i < n; i++) r = (r * 10) % MOD;
        printf("%d\n", r);
    }
    return 0;
}