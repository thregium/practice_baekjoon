#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 500000)명의 예상 등수가 주어질 때, 각 사람의 예상 등수와 실제 등수의 차의 합을 최소로 한다면,
그때의 값을 구한다. 단, 동석차가 나와서는 안 된다.

해결 방법 : 예상 등수 기준 오름차순으로 정렬한 것을 실제 등수로 그대로 매기는 것이 최적이다.
그때의 실제 등수와의 차의 합을 구하면 그것이 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

int a[524288];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        r += abs(a[i] - (i + 1));
    }
    printf("%lld", r);
    return 0;
}