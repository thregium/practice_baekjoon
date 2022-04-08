#include <stdio.h>

/*
문제 : N(N <= 1000)번의 거래동안의 입금과 출금액(<= 10^6)이 주어질 때, 그 과정에서 빚이 생기지 않기 위해
필요한 초기 자금의 최솟값을 구한다.

해결 방법 : 앞에서부터의 누적 합의 최솟값을 구한다. 이것이 시작점에서 돈이 0일 때 가장 많은 빚이므로
그 값의 절댓값이 답이 된다.

주요 알고리즘 : 수학, 누적 합

출처 : SCUSA 2021D2 F번 // MidC 2021 E번
*/

int main(void) {
    int n, t, sum = 0, worst = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        sum += t;
        if (sum < worst) worst = sum;
    }
    printf("%d", -worst);
    return 0;
}