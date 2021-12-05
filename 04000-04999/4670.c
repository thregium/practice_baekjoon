#include <stdio.h>

/*
문제 : N(N <= 100)페이지의 책을 인쇄하기 위해 각 종이에 찍어야 하는 페이지를 구한다.

해결 방법 : 페이지 수가 1인 경우 한쪽만 찍는 특수한 경우로, 따로 출력한다. 그 외의 경우는 각 페이지에
출력해야 하는 페이지 번호를 확인해 출력하되, N보다 큰 경우에는 Blank로 출력해야 한다.

주요 알고리즘 : 구현

출처 : MidC 1998 A번 // CTUF 2003 B번
*/

int main(void) {
    int n;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\booklet\\booklet.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\booklet\\booklet_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("Printing order for %d pages:\n", n);
        if (n == 1) {
            printf("Sheet 1, front: Blank, 1\n\n");
            continue;
        }
        for (int i = 0; i < ((n + 3) >> 2) << 1; i++) {
            printf("Sheet %d, ", (i >> 1) + 1);
            if (i & 1) {
                printf("back : %d, ", i + 1);
                if ((((n + 3) >> 2) << 2) - i > n) printf("Blank\n");
                else printf("%d\n", (((n + 3) >> 2) << 2) - i);
            }
            else {
                printf("front: ", i + 1);
                if ((((n + 3) >> 2) << 2) - i > n) printf("Blank, ");
                else printf("%d, ", (((n + 3) >> 2) << 2) - i);
                printf("%d\n", i + 1);
            }
        }
        printf("\n");
    }
    return 0;
}