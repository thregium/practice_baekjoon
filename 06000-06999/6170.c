#include <stdio.h>

/*
문제 : N(N <= 45)비트의 수 가운데 연속한 1이 없는 비트의 개수를 구한다.

해결 방법 : 점화식을 세워 보면 이는 피보나치 수의 N + 1번째 항의 값과 같음을 알 수 있다.
따라서, 이 값을 구하면 된다.

주요 알고리즘 : DP

출처 : TUD 2002 1번
*/

long long fibo[64];

int main(void) {
    int t, n;
    fibo[0] = 1;
    fibo[1] = 2;
    for (int i = 2; i <= 45; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        printf("Scenario #%d:\n%d\n\n", tt, fibo[n]);
    }
    return 0;
}