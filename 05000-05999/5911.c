#include <stdio.h>
#include <stdlib.h>

/*
문제 : B(B <= 10^9)의 예산으로 N(N <= 1000)개의 선물 가운데 최대한 많은 수를 사려고 한다. 각 선물은 10^9 이하의 고유한
가격과 배송비를 갖는다. 쿠폰이 1개 있고, 쿠폰을 사용해서 가격(배송비 미포함)을 절반으로 할인받을 수 있다면
살 수 있는 선물의 개수를 구한다.

해결 방법 : 모든 선물을 비용이 적게 필요한 순으로 정렬한다. 그 다음, 모든 선물에 대해 쿠폰을 한번씩 사용해본다.
만약 쿠폰을 사용한 가격이 B보다 크다면 바로 넘어가고 아니면 다른 선물들을 싼 것 부터 산다.
살 수 없어지는 선물까지 산 개수를 기록하고 그들 가운데 가장 큰 것을 고르면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 브루트 포스

출처 : USACO 2012J B1번
*/

int present[1024][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a + *((int*)a + 1);
    int bi = *(int*)b + *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, b, c, r = 0;
    long long d;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &present[i][0], &present[i][1]);
    }
    qsort(present, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        d = (present[i][0] >> 1) + present[i][1];
        if (d > b) continue;
        c = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            d += present[j][0] + present[j][1];
            if (d > b) break;
            c++;
        }
        if (c > r) r = c;
    }
    printf("%d", r);
    return 0;
}