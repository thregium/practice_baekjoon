#include <stdio.h>
#define MOD 1000000007

/*
문제 : A와 B로만 이루어진 K자리 수에서 C의 개수를 구한다.

해결 방법 : 만약 A와 B가 서로 다른 수이 경우 A 또는 B의 개수는 2^(k - 1) * k와 같다. 단, K = 0인 경우에는 0이 되어야 한다.
A와 B가 같은 경우에는 A = B의 개수는 K개이다. 또한, C가 A, B 둘 다와 다른 경우에는 당연히 0개가 된다.

주요 알고리즘 : 수학, 조합론, 케이스 워크

출처 : CTU 2019 B1번
*/

long long b2[1024];

int main(void) {
    int a, b, c, k;
    b2[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        b2[i] = b2[i - 1] * 2 % MOD;
    }
    scanf("%d %d %d %d", &a, &b, &k, &c);
    if (k == 0 || (c != a && c != b)) {
        printf("0");
    }
    else if (c == a && c == b) {
        printf("%d", k);
    }
    else {
        printf("%lld", b2[k - 1] * k % MOD);
    }
    return 0;
}