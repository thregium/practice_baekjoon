#include <stdio.h>

/*
문제 : 자연수 N(N <= 12)이 주어질 때, N을 서로 다른 두 자연수의 합으로 표현하는 방법을 모두 출력한다.
단, 두 번째 자연수가 더 커야 한다.

해결 방법 : N의 제한이 매우 작으므로 직접 구해준다.

주요 알고리즘 : 구현?

출처 : HSPC 2012 P1번
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("Pairs for %d: ", n);
        if (n == 3) printf("1 2");
        else if (n == 4) printf("1 3");
        else if (n == 5) printf("1 4, 2 3");
        else if (n == 6) printf("1 5, 2 4");
        else if (n == 7) printf("1 6, 2 5, 3 4");
        else if (n == 8) printf("1 7, 2 6, 3 5");
        else if (n == 9) printf("1 8, 2 7, 3 6, 4 5");
        else if (n == 10) printf("1 9, 2 8, 3 7, 4 6");
        else if (n == 11) printf("1 10, 2 9, 3 8, 4 7, 5 6");
        else if (n == 12) printf("1 11, 2 10, 3 9, 4 8, 5 7");
        printf("\n");
    }
    return 0;
}