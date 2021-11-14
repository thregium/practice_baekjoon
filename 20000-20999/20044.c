#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N * 2(N <= 5000)개의 자연수(<= 100000)가 주어질 때, 자연수를 2개씩 짝지어서 합이 가장 작은 것을
가장 크게 하려고 할 때, 그 합을 구한다.

해결 방법 : 자연수들을 정렬한 다음, 양 끝에서부터 서로 더해나가며 그들 가운데 가장 작은 것을 구하는 것이 최선이다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : Seoul 2020I I번
*/

int a[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n * 2, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] + a[n * 2 - i - 1] < r) r = a[i] + a[n * 2 - i - 1];
    }
    if (r == INF) return 1;
    printf("%d", r);
    return 0;
}