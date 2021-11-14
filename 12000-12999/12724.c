#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ���� �̷���� �� ������ ��(|| <= 10000, ����) ������ �ٲپ� ������ ���� �ִ밡 �ǵ��� �Ѵٸ�,
�׶��� ������ ���� ���Ѵ�.

�ذ� ��� : �� ���͸� ���� ���������� ������������ ������ ����, ������ ���ϴ� ���� �����̴�.
������ �̿��ϸ� ������ �� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : GCJ 20081A A2��
*/

int x[1024], y[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n;
    long long r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &y[i]);
        }
        qsort(x, n, sizeof(int), cmp1);
        qsort(y, n, sizeof(int), cmp2);
        r = 0;
        for (int i = 0; i < n; i++) {
            r += (long long)x[i] * y[i];
        }
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}