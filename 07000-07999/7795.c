#include <stdio.h>
#include <stdlib.h>

/*
문제 : N개의 자연수로 이루어진 첫 번째 집합과 M(N, M <= 20000)개의 자연수로 이루어진 두 번째 집합이 주어질 때,
첫 번째 집합의 수가 두 번째 집합의 수보다 큰 순서쌍의 개수를 구한다.

해결 방법 : 두 수를 내림차순으로 정렬한 후, 투 포인터 알고리즘을 이용해 각 수마다 더 작은 수의 개수를
빠르게 구해나가며 더하면 된다.

주요 알고리즘 : 정렬, 투 포인터

출처 : INC 2008 D번
*/

int a[20480], b[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, m, p;
    long long r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        r = 0;
        qsort(a, n, sizeof(int), cmp1);
        qsort(b, m, sizeof(int), cmp1);

        p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && b[p] >= a[i]) p++;
            r += m - p;
        }
        printf("%lld\n", r);
    }
    return 0;
}