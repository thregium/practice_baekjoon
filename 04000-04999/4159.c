#include <stdio.h>
#include <stdlib.h>

/*
문제 : 1422마일을 왕복하려 한다. 한번 주유시 200만큼 이동이 가능하다면 이동 가능한지 구한다.

해결 방법 : 200씩 움직이며 확인한다. 200 범위에 없으면 안 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : Waterloo 100926 B번
*/

int oil[2048];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l, r, i, j;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &oil[i]);
        }
        for (i = 0; i < 1322;) {
            for (j = 0; j < n && (oil[j] <= i || oil[j] > i + 200); j++);
            if (j == n) break;
            i = oil[j];
        }
        if (i < 1322) printf("IMPOSSIBLE\n");
        else printf("POSSIBLE\n");
    }
    return 0;
}