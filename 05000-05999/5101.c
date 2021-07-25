#include <stdio.h>

/*
문제 : 초항이 A이고 공차가 D인 등차수열에서 N인 항이 있는지 확인하고, 있다면 몇 번째 항인지 구한다.

해결 방법 : A부터 차례로 확인해 나가다가 N을 넘어가면 반복을 종료하고 N인지 확인한다. N이라면 해당하는 번째를 출력하고,
아니라면 없는 것이다.

주요 알고리즘 : 수학

출처 : NZPC 2010 B번
*/

int main(void) {
    int a, d, n, i;
    while (1) {
        scanf("%d %d %d", &a, &d, &n);
        if (d > 0) {
            for (i = 1; a < n; i++) a += d;
            if (a == n) printf("%d\n", i);
            else printf("X\n");
        }
        else if (d < 0) {
            for (i = 1; a > n; i++) a += d;
            if (a == n) printf("%d\n", i);
            else printf("X\n");
        }
        else break;
    }
    return 0;
}