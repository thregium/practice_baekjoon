#include <stdio.h>

/*
문제 : N(N <= 10000)개의 수 가운데 0과 1의 등장 횟수를 각각 구한다.

해결 방법 : 직접 세보면 된다.

주요 알고리즘 : 구현

출처 : Latin 2005 PA번
*/

int main(void) {
    int n, r, m, j;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        m = 0, j = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &r);
            if (r) j++;
            else m++;
        }
        printf("Mary won %d times and John won %d times\n", m, j);
    }
    return 0;
}