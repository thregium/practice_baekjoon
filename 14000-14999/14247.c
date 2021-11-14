#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)그루의 나무가 있다. 각 나무의 초기 높이와 1일당 자라는 높이가 주어진다면,
N일간 자를 수 있는 가장 많은 나무의 양을 구한다.

해결 방법 : 나무의 자라는 양 순서대로 정렬한 다음 천천히 자르는 것 부터 자르는 것이 최적이다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

int grow[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        r += x;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &grow[i]);
    }
    qsort(grow, n, sizeof(int), cmp1);
    for (long long i = 0; i < n; i++) {
        r += grow[i] * i;
    }
    printf("%lld", r);
    return 0;
}