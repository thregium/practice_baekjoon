#include <stdio.h>

/*
문제 : N(N <= 500000)개의 0 이상 10^9 이하의 정수를 오름차순으로 정렬했을 때, 마지막에 오는 수를 구한다.

해결 방법 : N개의 수들 가운데 최댓값을 구하면 된다.

주요 알고리즘 : 구현

출처 : 인하대 2019 A번
*/

int main(void) {
    int n, a, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a > r) r = a;
    }
    printf("%d", r);
    return 0;
}