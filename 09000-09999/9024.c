#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : 서로 다른 N(N <= 10^6)개의 정수(|| <= 10^8)가 주어질 때, 합이 K(|K| <= 10^8)에 가장 가까운
쌍의 개수를 구한다.

해결 방법 : 배열을 정렬한 다음, 양쪽에서 포인터를 좁혀가며 양쪽 합이 K에 가까운 수들의 후보를 확인한다.
그 과정에서 K와의 차이의 최솟값과 그러한 쌍의 개수를 세면 된다.

주요 알고리즘 : 정렬, 투 포인터

출처 : Daejeon 2011I I번
*/

int a[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, k, lt, rt, best, bcnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        lt = 0, rt = n - 1, best = INF, bcnt = 0;
        while (lt < rt) {
            if (abs(a[rt] + a[lt] - k) < best) {
                best = abs(a[rt] + a[lt] - k);
                bcnt = 1;
            }
            else if (abs(a[rt] + a[lt] - k) == best) bcnt++;
            if (a[rt] + a[lt] < k) lt++;
            else rt--;
        }
        if (best == INF) return 1;
        printf("%d\n", bcnt);
    }
    return 0;
}