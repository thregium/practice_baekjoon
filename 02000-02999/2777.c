#include <stdio.h>

/*
문제 : N(N <= 10^9)이 주어질 때, 모든 자릿수의 곱이 N인 수 중 가장 작은 수의 자리를 구한다.
불가능한 경우 -1을 출력한다.

해결 방법 : 9부터 2까지 차례로 나누어 떨어지는지 확인하며 나누어 떨어지는 경우 자릿수를 늘려나간다.
어느 것으로도 나누어 떨어지지 않는다면 -1을 출력한다. 1이 되면 자릿수를 출력한다.
단, 1인 경우에는 답이 1이어야 한다.

주요 알고리즘 : 그리디 알고리즘, 수학
*/

int main(void) {
    int t, n, p = 1, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n == 1) {
            printf("1\n");
            continue;
        }
        r = 0, p = 1;
        while (n > 1) {
            p = 1;
            for (int i = 9; i >= 2; i--) {
                if (n % i == 0) {
                    n /= i;
                    p = 0;
                    break;
                }
            }
            if (p) {
                printf("-1\n");
                break;
            }
            r++;
        }
        if (!p) printf("%d\n", r);
    }
    return 0;
}