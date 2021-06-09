#include <stdio.h>
#include <stdlib.h>
#define SZ 131072

/*
���� : 1���� N(N <= 100000)������ ���� �̷���� ������ Ĭ���� ��Ʈ�Ѵ�.
�̶�, �� �������� ��ȸ swap ������ �Ͼ���� ���Ѵ�.

�ذ� ��� : ���� ������ ������ �� ������ �� ���� ��ȣ���� ������� ã�´�.
�׸��� �ϴ� ó�� ���¿����� ��� ���� �����ִ� �����̹Ƿ� ���׸�Ʈ Ʈ���� ��� ���� ���� 1�� �������ش�.
�� �������δ� ���� ���� ���� ���� ū ������ ������� ã�ư��� �� ���� �� �Ǵ� �� ���� ���� �� �����ִ� ���� ������ ���Ѵ�.
������ ���� �������� �� ���� ����ϰ�, ���� Ȯ���� ���� ���׸�Ʈ Ʈ������ 0���� �ٲٸ� �ȴ�.
�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��

��ó : COCI 07/08#2 4��
*/

int a[103000], idx[103000], seg[SZ * 2];

int cmp1(const void* x, const void* y) {
    int ai = a[*(int*)x];
    int bi = a[*(int*)y];
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void update(int p, int x) {
    seg[SZ + p] = x;
    for (int i = ((SZ + p) >> 1); i >= 1; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int find(int fs, int fe, int ss, int se, int d) {
    if (ss > fe || se < fs) return 0;
    else if (ss >= fs && se <= fe) return seg[d];
    return find(fs, fe, ss, (ss + se) >> 1, d << 1) + find(fs, fe, ((ss + se) >> 1) + 1, se, (d << 1) + 1);
}

int main(void) {
    int n, p = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        idx[i] = a[i];
    }
    qsort(idx + 1, n, sizeof(int), cmp1);

    for (int i = 1; i <= n; i++) seg[SZ + i] = 1;
    for (int j = SZ - 1; j > 0; j--) {
        seg[j] = seg[j << 1] + seg[(j << 1) + 1];
    }
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            p = idx[n - (i >> 1)];
            printf("%d\n", find(p + 1, n, 0, SZ - 1, 1));
        }
        else {
            p = idx[1 + (i >> 1)];
            printf("%d\n", find(1, p - 1, 0, SZ - 1, 1));
        }
        update(p, 0);
    }
    return 0;
}