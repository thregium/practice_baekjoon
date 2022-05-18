#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 자연수(<= 10^18)와 자연수 K(K <= 10^12)가 주어질 때,
K의 배수이며 주어지지 않은 가장 작은 자연수를 구한다.

해결 방법 : N이 최대 10^6개이므로 K * (10^6 + 1) 이내에는 반드시 답이 존재하게 된다.
따라서, X가 K의 10^6 + 1배수 이내의 배수인 경우 그 배숫값을 체크하는 배열에 체크해둔다.
그 다음, 1부터 N + 1까지 돌면서 체크되지 않은 첫 수에 대해 * K를 한 값을 출력하면 된다.

주요 알고리즘 : 수학, 비둘기집 원리?

출처 : JPOI 2008 2-1번
*/

char chk[1048576];

int main(void) {
    int n;
    long long k, x;
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        if (x < k * 1048576 && x % k == 0) chk[x / k] = 1;
    }
    for (int i = 1;; i++) {
        if (!chk[i]) {
            printf("%lld", i * k);
            return 0;
        }
    }
    while (1);
    return 1;
}