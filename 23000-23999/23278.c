#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 50)개의 점수(0 <=, <= 100, 정수)가 주어질 때, 가장 낮은 L개와 가장 높은 H개(L + H < N)를 제외한
점수의 평균을 구한다.

해결 방법 : 각 점수들을 정렬한 다음, L + 1번째부터 N - H번째까지의 합을 구한다. 그 값을 N - L - H로 나눈 것이 답이 된다.

주요 알고리즘 : 수학, 사칙연산, 정렬

출처 : TCCC 2007Q1 1번
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l, h, s = 0;
    scanf("%d %d %d", &n, &l, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = l; i < n - h; i++) {
        s += a[i];
    }
    printf("%.16f", s / ((double)n - l - h));
    return 0;
}