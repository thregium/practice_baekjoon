#include <stdio.h>

/*
문제 : 자연수 N(N <= 1000)을 2진법부터 N진법까지로 표현했을 때 0의 수 합을 구한다.

해결 방법 : 모든 진법에 대해 0의 수를 각각 구해서 그 합을 구하면 된다. 각 진법에 대해 끝에 붙는 0의 수는
해당 진수로 나눌 수 있는(완전히 나누어 떨어지는) 횟수와 같다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int t, n, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = n; j; j /= i) {
                if (j % i) break;
                r++;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}