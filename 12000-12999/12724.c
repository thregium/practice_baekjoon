#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 수로 이루어진 두 벡터의 값(|| <= 10000, 정수) 순서를 바꾸어 내적의 값을 최대가 되도록 한다면,
그때의 내적의 값을 구한다.

해결 방법 : 두 벡터를 각각 오름차순과 내림차순으로 정렬한 다음, 내적을 구하는 것이 최적이다.
정렬을 이용하면 빠르게 할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : GCJ 20081A A2번
*/

int x[1024], y[1024];

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
    int t, n;
    long long r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &y[i]);
        }
        qsort(x, n, sizeof(int), cmp1);
        qsort(y, n, sizeof(int), cmp2);
        r = 0;
        for (int i = 0; i < n; i++) {
            r += (long long)x[i] * y[i];
        }
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}