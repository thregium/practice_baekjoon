#include <stdio.h>
#include <stdlib.h>

/*
문제 : 일렬로 놓인 N(N <= 10000)개 땅의 pH 값(0 <= pH <= 14)이 소숫점 아래 6자리까지 주어진다.
이때, M(M <= 10000)개의 쿼리에 응답한다.
[L, R] 범위의 땅에서 pH 값이 같은 땅이 과반인 지 구한다.
(제한시간 2초)

해결 방법 : 각 땅의 pH값이 다른 지 여부만 중요하므로 압축을 통해 값의 개수와 범위를 N 이내로 줄인다.
그리고 N, M에 비해 제한시간이 크므로 각 쿼리에 응답할 때에는 직접 개수를 세 나가면 된다.

주요 알고리즘 : 브루트 포스, 값 압축

출처 : MidC 2019 H번
*/

int ph[10240][3], cnt[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, x, y, l, r, h;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d.%d", &x, &y);
        ph[i][0] = x * 1000000 + y;
        ph[i][1] = i;
    }
    qsort(ph, n, sizeof(int) * 3, cmp1);
    ph[0][2] = 1;
    for (int i = 1; i < n; i++) {
        if (ph[i][0] == ph[i - 1][0]) ph[i][2] = ph[i - 1][2];
        else ph[i][2] = ph[i - 1][2] + 1;
    }
    qsort(ph, n, sizeof(int) * 3, cmp2);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l, &r);
        h = 0;
        for (int j = l - 1; j < r; j++) {
            cnt[ph[j][2]]++;
            if (cnt[ph[j][2]] > h) h = cnt[ph[j][2]];
        }
        for (int j = 1; j <= n; j++) cnt[j] = 0;
        if (h * 2 > r - l + 1) printf("usable\n");
        else printf("unusable\n");
    }
    return 0;
}