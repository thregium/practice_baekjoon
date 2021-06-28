#include <stdio.h>

/*
문제 : N장으로 된 시험지가 주어질 때, P번 장과 같은 장에 있는 모든 페이지들을 순서대로 출력한다.

해결 방법 : 각 페이지별로 몇 번째 장인지 구한 후, 1부터 N까지 살펴보며 P와 같은 장이며 다른 페이지인 수들을 찾으면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : MidC 2013 C번
*/

int main(void) {
    int n, p, pp, ppp;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &p);
        if (p <= (n >> 1)) pp = ((p + 1) >> 1);
        else pp = ((n - p + 2) >> 1);
        for (int i = 1; i <= n; i++) {
            if (i <= (n >> 1)) ppp = ((i + 1) >> 1);
            else ppp = ((n - i + 2) >> 1);
            if (ppp == pp && p != i) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}