#include <stdio.h>

/*
문제 : N0이 주어질 때, 주어진 방식으로 계산한 후 계산 결과를 구한다.(이하 생략)

해결 방법 : 주어진 방식대로 계산한다.

주요 알고리즘 : 구현, 시뮬레이션, 사칙연산

출처 : Arab 2009 D번
*/

int main(void) {
    int n0, n1, n2, n3, n4;
    for (int tt = 1;; tt++) {
        scanf("%d", &n0);
        if (n0 == 0) break;
        n1 = 3 * n0;
        if (n1 & 1) n2 = (n1 + 1) / 2;
        else n2 = n1 / 2;
        n3 = 3 * n2;
        n4 = n3 / 9;

        printf("%d. ", tt);
        if (n1 & 1) {
            printf("odd %d\n", n4);
        }
        else {
            printf("even %d\n", n4);
        }
    }
    return 0;
}