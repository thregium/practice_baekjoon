#include <stdio.h>
#define MOD 1000000007

/*
문제 : X가 10^8 이하의 음이 아닌 정수일 때 N(N <= 10^6)차 다항식의 값을 구한다. 각 항의 계수는 100 이하다.
각 항은 X^N항부터 상수항까지 모든 항이 내림차순으로 주어진다.

해결 방법 : 차수가 큰 항부터 순서대로 주어지기 때문에 큰 항의 값을 구한 후 X를 차례로 곱해가면
해당 항의 X 개수만큼을 곱할 수 있고, 다항식의 값도 구할 수 있다.

주요 알고리즘 : 구현, 수학, 정수론

출처 : SUAPC 2020 D2B번
*/

int poly[1048576];

int main(void) {
    int n, x, t, res = 0;
    scanf("%d %d", &n, &x);
    for (int i = n; i >= 0; i--) {
        scanf("%d %d", &poly[n - i], &t);
        if (t != i) return 1;
        res = (long long)res * x % MOD;
        res += poly[n - i];
    }
    printf("%d", res);
    return 0;
}