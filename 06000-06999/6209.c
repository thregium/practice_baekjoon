#include <stdio.h>
#include <stdlib.h>

/*
문제 : 자연수 D(D <= 10^9)가 주어지고, N(0 <= N <= 50000)개의 자연수(0 <, < D)가 주어진다. 이 자연수들 가운데 M개를
지운 후 정렬했을 때, 인접한 두 자연수의 차이 가운데 최솟값 또는 D와 가장 큰 수의 차이 또는 0과 가장 작은 수의 차이
가운데 가장 작은 값을 가장 크게 했을 때, 그 값을 구한다.

해결 방법 : 매개 변수 탐색을 이용한다. 최소 거리를 X라고 했을 때 지우지 않아도 되는 자연수의 개수를 Y라고 하면
Y가 N - M 이하인 가장 큰 X를 찾으면 된다. 또한, X를 안다면 Y는 N개의 수를 정렬한 다음,
마지막으로 확인한 수와 차이가 X 이하일 때마다 개수를 세면 알 수 있으므로 이 방법을 통해 답을 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 파라메트릭

출처 : USACO 2006 S3번
*/

int a[51200];

int maxcount(int n, int x) {
    int r = -1, last = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (a[i] >= a[last] + x) {
            r++;
            last = i;
        }
    }
    return r;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int d, n, m, l = -1, h = 1012345678;
    scanf("%d %d %d", &d, &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a + 1, n, sizeof(int), cmp1);
    a[n + 1] = d;

    while (l < h) {
        if (maxcount(n, (l + h + 1) >> 1) >= n - m) l = ((l + h + 1) >> 1);
        else h = ((l + h + 1) >> 1) - 1;
    }
    printf("%d", l);
    return 0;
}