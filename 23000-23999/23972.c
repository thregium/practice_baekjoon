#include <stdio.h>

/*
문제 : K원을 주면 남은 돈을 N(1 <= N, K <= 10^9)배 한다고 하면, 이것이 손해가 아니기 위해서 필요한 원래 소지금을 구한다.
항상 손해인 경우 -1을 출력한다.

해결 방법 : N이 1인 경우 항상 손해이므로 -1을 출력한다. 그 외의 경우는 ceil(k / (n - 1))원이 준 후 남으면 손해가 아니므로,
이 값에 k를 더한 값이 답이 된다.

주요 알고리즘 : 수학

출처 : 한양대E 2021 B번
*/

int main(void) {
    int k, n;
    scanf("%d %d", &k, &n);
    if (n <= 1) printf("-1");
    else printf("%d", (k + n - 2) / (n - 1) + k);
    return 0;
}