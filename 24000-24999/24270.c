#include <stdio.h>
#define MOD 1000000007

/*
문제 : N(N <= 500000)개의 일을 K(K <= 10^9)일동안 겹치지 않게 하나씩 하는 방법의 가짓수를 구한다.
각 일의 길이는 1 이상이고, 전체 일의 일 수 합은 K 이하다.

해결 방법 : 각 일들 사이에 일을 하지 않는 날들을 집어넣고 순열의 가짓수를 세면 된다.
이는 N! * (N+b)CN과 같고(이때 b는 일을 하지 않는 날의 수), 이는 N+1부터 N+b까지를 모두 곱한 것과
같으므로 이 값을 계산하면 된다.

주요 알고리즘 : 수학, 조합론

출처 : HBOJ 2022 C번
*/

int main(void) {
    int n, k, x, r = 1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        k -= x;
    }
    for (long long i = k + 1; i <= k + n; i++) r = (r * i) % MOD;
    printf("%d", r);
    return 0;
}