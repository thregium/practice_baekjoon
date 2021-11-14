#include <stdio.h>
#include <stdlib.h>
#define INF 0x7A35090F

/*
문제 : 크기 N(N <= 100000)의 배열(정수, || <= 10^9)이 주어질 때, 이 배열에서 차이가 M(M <= 2 * 10^9) 이상이면서
가장 작은 두 수의 차이를 구한다.

해결 방법 : 배열을 정렬한 다음, 왼쪽부터 시작점과 끝점을 이동시킨다. 구 수의 차이가 M 미만인 경우 끝점을 이동시키고,
이상인 경우 결괏값을 갱신하고 시작점을 옮긴다. 이는 끝점이 배열을 벗어날 때 까지 반복하면 된다.

주요 알고리즘 : 정렬, 투 포인터
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, s = 0, e = 0, r = INF;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    while (e < n) {
        while (e < n && a[e] - a[s] < m) e++;
        if (e == n) break;
        if (a[e] - a[s] <= r) r = a[e] - a[s];
        s++;
    }
    printf("%d", r);
    return 0;
}