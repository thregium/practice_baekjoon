#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 물건 가격(<= 1000, 자연수)이 주어질 때,
주어진 예산 B(B <= 100000)으로 살 수 있는 물건의 최대 개수를 구한다.

해결 방법 : 가장 싼 것 부터 정렬한 후, 그 순서대로 최대한 사보면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : GKS 2020A A번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, b, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &b);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        r = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= b) {
                b -= a[i];
                r++;
            }
            else break;
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}