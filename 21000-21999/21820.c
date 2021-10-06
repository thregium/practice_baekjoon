#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)개의 논문의 인용 수가 주어진다. 이때, L(L <= 100000)개의 논문에 자기인용을 할 수 있다면
얻을 수 있는 H-index의 최댓값을 구한다.

해결 방법 : 먼저, 각 논문의 인용 수를 내림차순으로 정렬한다. 그 다음, 각 논문의 H-index를 매개 변수 탐색을 통해
찾으면 된다. 목표로 하는 H-index를 확인하고, H개의 논문 가운데 목표치에 모자란 논문을 1회씩 자가인용하여
목표치를 달성할 수 있는지, 가능하다면 L회 이내로 인용하였는지 확인하고, 둘 다인 경우에는 범위를 높이고
아니라며 범위를 낮춰가며 답을 찾아가면 된다.

주요 알고리즘 : 파라메트릭, 정렬

출처 : USACO 2021O B1번
*/

int cit[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

long long hdx(int n, int h) {
    long long r = 0;
    for (int i = 0; i < h; i++) {
        if (cit[i] < h - 1) return INF;
        else if (cit[i] < h) r++;
    }
    return r;
}

int main(void) {
    int n, l, lo, hi;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cit[i]);
    }
    qsort(cit, n, sizeof(int), cmp1);
    lo = 0, hi = n;
    while (lo < hi) {
        if (hdx(n, (lo + hi + 1) >> 1) <= l) lo = ((lo + hi + 1) >> 1);
        else hi = ((lo + hi + 1) >> 1) - 1;
    }
    printf("%d", lo);
    return 0;
}