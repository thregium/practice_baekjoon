#include <stdio.h>
#include <stdlib.h>

/*
���� : �ڿ��� D(D <= 10^9)�� �־�����, N(0 <= N <= 50000)���� �ڿ���(0 <, < D)�� �־�����. �� �ڿ����� ��� M����
���� �� �������� ��, ������ �� �ڿ����� ���� ��� �ּڰ� �Ǵ� D�� ���� ū ���� ���� �Ǵ� 0�� ���� ���� ���� ����
��� ���� ���� ���� ���� ũ�� ���� ��, �� ���� ���Ѵ�.

�ذ� ��� : �Ű� ���� Ž���� �̿��Ѵ�. �ּ� �Ÿ��� X��� ���� �� ������ �ʾƵ� �Ǵ� �ڿ����� ������ Y��� �ϸ�
Y�� N - M ������ ���� ū X�� ã���� �ȴ�. ����, X�� �ȴٸ� Y�� N���� ���� ������ ����,
���������� Ȯ���� ���� ���̰� X ������ ������ ������ ���� �� �� �����Ƿ� �� ����� ���� ���� ���� �� �ִ�.

�ֿ� �˰����� : �׸��� �˰�����, �Ķ��Ʈ��

��ó : USACO 2006 S3��
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