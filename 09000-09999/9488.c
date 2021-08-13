#include <stdio.h>

/*
문제 : N(N <= 10^6)번째 사면체수를 구한다.

해결 방법 : N번째 삼각수를 미리 찾은 누적 합을 한번 더 구해서 사면체수를 만들어두면 된다.

주요 알고리즘 : 수학

출처 : SEUSA 2013D2 B번
*/

long long r[1048576];

int main(void) {
    int n;
    for (int i = 1; i <= 1000000; i++) {
        r[i] = r[i - 1] + i;
    }
    for (int i = 1; i <= 1000000; i++) {
        r[i] += r[i - 1];
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%lld\n", r[n]);
    }
    return 0;
}