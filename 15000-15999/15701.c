#include <stdio.h>

/*
문제 : 두 수의 곱이 N(N <= 10^9)인 순서쌍의 수를 구한다.

해결 방법 : 1부터 sqrt(N)까지의 수를 확인하며 N을 나눌 수 있는 수라면 sqrt(N)인 경우 결괏값에 1을 더하고
그 외의 경우 결괏값에 2를 더하면 된다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        if (i * i == n) r++;
        else r += 2;
    }
    printf("%d", r);
    return 0;
}