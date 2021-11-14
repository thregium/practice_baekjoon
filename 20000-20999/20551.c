#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 정수(|| <= 10^9)로 이루어진 배열을 정렬한 배열에서 M(M <= 200000)개의 쿼리에 응답한다.
정렬한 배열에서 D가 처음 나오는 곳이 어디인지 구한다. 없다면 -1을 출력한다.

해결 방법 : 먼저 배열을 정렬한 다음 중복을 제외하고 나오는 첫 번째 위치들을 같이 저장한다.
그 다음, 각 쿼리에 대해 bsearch() 함수를 이용해 나오는 위치를 확인하고 그에 대응하는 첫 위치를 출력하면 된다.
물론 없는 경우 -1을 출력한다.

주요 알고리즘 : 정렬, 이분 탐색

출처 : 인하대 2020U B번
*/

int a[204800], a2[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, sz = 0, x;
    int* p;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;
        a2[sz][0] = a[i];
        a2[sz++][1] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        p = bsearch(&x, a2, sz, sizeof(int) * 2, cmp1);
        if (p == NULL) printf("-1\n");
        else printf("%d\n", *(p + 1));
    }
    return 0;
}