#include <stdio.h>
#include <stdlib.h>

/*
���� : N���� �ڿ����� �̷���� ù ��° ���հ� M(N, M <= 20000)���� �ڿ����� �̷���� �� ��° ������ �־��� ��,
ù ��° ������ ���� �� ��° ������ ������ ū �������� ������ ���Ѵ�.

�ذ� ��� : �� ���� ������������ ������ ��, �� ������ �˰����� �̿��� �� ������ �� ���� ���� ������
������ ���س����� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �� ������

��ó : INC 2008 D��
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