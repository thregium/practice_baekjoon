#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 물건과 M(M <= 200000)명의 고객이 있다. 각 고객의 만족도는
물건의 가치 - 지불한 가격으로 정해질 때, 만족도의 합의 최댓값을 구한다.
물건의 가치와 지불한 가격은 10^9 이하의 자연수이다.

해결 방법 : 모든 고객이 모든 물건을 사는 경우 어떻게 연결되든 항상 만족도 합은 같을 것이다.
이를 역으로 생각하여 가장 적게 지불할 고객부터 좋은 물건을 주도록 하면 만족도가 음수인 고객을 제외할 시
만족도 합이 최대가 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : DGIST 2022 B번
*/

int a[204800], b[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m;
    long long r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    qsort(a, n, sizeof(int), cmp2);
    qsort(b, m, sizeof(int), cmp1);
    for (int i = 0; i < m && i < n; i++) {
        if (b[i] > a[i]) break;
        else r += a[i] - b[i];
    }
    printf("%lld", r);
    return 0;
}