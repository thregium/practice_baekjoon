#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)장의 카드 가운데 L(1 <= L <= N)장의 임의의 자연수가 적힌 카드(<= 1000)를 뽑아
카드의 수 합이 더 큰 사람이 이기는 게임이 있다. 두 명이 가진 카드의 모든 수들이 주어질 때,
첫 번째 사람이 항상 두 번째 사람을 이길 지 구한다.

해결 방법 : 두 번째 사람에게 최선의 경우는 두 번째 사람은 가장 큰 카드만 뽑고,
첫 번째 사람은 가장 작은 카드만 뽑는 경우이다. 이를 위해서는 두 사람의 카드를 각각 오름차순,
내림차순으로 정렬한 다음 앞에서부터 L개의 카드를 뽑고 합을 비교하면 된다.
첫 번째 사람의 카드 합이 더 크면 조건을 만족하고, 아니라면 만족하지 않는 것이다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : RCC 2015Q1 A번
*/

int a[128], b[128];

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
    int t, n, l, as, bs;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        qsort(b, n, sizeof(int), cmp2);
        as = 0, bs = 0;
        for (int i = 0; i < l; i++) {
            as += a[i];
            bs += b[i];
        }
        printf("%s\n", as > bs ? "YES" : "NO");
    }
    return 0;
}