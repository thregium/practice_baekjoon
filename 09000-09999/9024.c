#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : ���� �ٸ� N(N <= 10^6)���� ����(|| <= 10^8)�� �־��� ��, ���� K(|K| <= 10^8)�� ���� �����
���� ������ ���Ѵ�.

�ذ� ��� : �迭�� ������ ����, ���ʿ��� �����͸� �������� ���� ���� K�� ����� ������ �ĺ��� Ȯ���Ѵ�.
�� �������� K���� ������ �ּڰ��� �׷��� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, �� ������

��ó : Daejeon 2011I I��
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