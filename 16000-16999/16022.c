#include <stdio.h>
#include <stdlib.h>
#define INF 0x7A35090F

/*
문제 : N(N <= 100)개의 정수로 수직선상의 각 지점의 위치(|| <= 10^9)가 주어질 때,
각 지점과 가장 가까운 구간의 길이가 가장 좁은 점의 해당 길이를 구한다.

해결 방법 : 가장 가까운 구간의 길이는 양 옆 점간의 거리의 절반과 같다.
따라서, 모든 정수를 정렬한 다음, 2번째 점부터 뒤에서 2번째 점까지 보며 양 옆 점 사이 거리가
가장 짧은 것을 고른 다음 그 값의 절반을 하면 된다.

주요 알고리즘 : 정렬

출처 : CCC 2018S 1번
*/

int a[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 1; i < n - 1; i++) {
        r = small(r, a[i + 1] - a[i - 1]);
    }
    printf("%d.%d", r >> 1, (r & 1) * 5);
    return 0;
}