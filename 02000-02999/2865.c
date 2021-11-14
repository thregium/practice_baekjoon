#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)명 가운데 K(K <= N)명을 뽑으려 한다. 각 사람은 M(M <= 100)개의 장르에 대한 능력치가 주어진다.
한 사람당 한 개의 장르만 할 수 있다면 K명이 하는 능력치의 합이 최대가 될 때의 능력치 합을 구한다.

해결 방법 : 각 사람의 장르들을 능력치에 대해 내림차순으로 정렬하고, 가장 능력치가 높은 장르를 기준으로 정렬하여
사람 K명을 뽑는다. 그 사람들의 가장 높은 장르의 능력치 합을 구하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : COCI 10/11#3 3번
*/

double score[128][128];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, k, x;
    double r = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            scanf("%lf", &score[x - 1][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        qsort(score[i], m, sizeof(double), cmp1);
    }
    qsort(score, n, sizeof(double) * 128, cmp1);
    for (int i = 0; i < k; i++) {
        r += score[i][0];
    }
    printf("%.1f", r);
    return 0;
}