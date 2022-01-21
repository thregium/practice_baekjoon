#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 용액의 밀도(<= 100000, 자연수)와 각 용액의 색(소문자, 20자)이 주어진다.
다시 M(M <= 100000)개의 색이 주어질 때, 위에서부터 순서대로 밀도 순서를 지키며
각 용액을 차례로 넣을 수 있는 지 구한다. 밀도가 같은 것이 중간에 나오면 안 된다.

해결 방법 : 각 용액들을 밀도 순서대로 정렬한 다음, 주어진 색마다 앞에서부터 순서대로
첫 번째 같은 색을 다음 용액으로 선정하고 이를 반복하며 모든 색을 차례로 넣을 수 있는 지 확인하면 된다.
단, 밀도가 같은 것이 나오면 안 되기 때문에 최근 용액과 밀도가 같은 것은 넘어가며 확인해야 한다.

주요 알고리즘 : 정렬, 투 포인터

출처 : JAG 2018S3 B번
*/

typedef struct liq {
    int d;
    char c[24];
} liq;

char buff[32];
liq lq[103000];

int cmp1(const void* a, const void* b) {
    liq ai = *(liq*)a;
    liq bi = *(liq*)b;
    return ai.d > bi.d ? 1 : ai.d == bi.d ? 0 : -1;
}

int main(void) {
    int n, m, p = 0, last = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", lq[i].c, &lq[i].d);
    }
    qsort(lq, n, sizeof(liq), cmp1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        while (p < n && lq[p].d <= last) p++;
        while (p < n && strcmp(lq[p].c, buff)) p++;
        last = lq[p].d;
        if (p == n) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}