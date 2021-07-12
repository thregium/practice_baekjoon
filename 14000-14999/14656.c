#include <stdio.h>

/*
문제 : N(N <= 20000)개의 수들 중 1부터 N까지 순서대로 놓여있지 않은 수의 개수를 구한다.

해결 방법 : 해당 순서의 수를 찾고 다른 것의 수를 센다.

주요 알고리즘 : 구현

출처 : 선린 1회 G번
*/

int main(void) {
    int n, x, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (i != x) r++;
    }
    printf("%d", r);
    return 0;
}