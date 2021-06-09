#include <stdio.h>
#include <stdlib.h>
#define SZ 524288

/*
���� : 1���� N(N <= 500000)���� �̷���� 3���� ������ �־�����.
�� �������� (�ٸ� ���� �� �� ���� ��ο��� ���� ���� ��)�� ���� ���� ������ ���Ѵ�.

�ذ� ��� : ���� �� ���� ù ��° ������ ���� ��ȣ ������ �����Ѵ�.
�� �������δ� ������ ������� Ȯ���ϸ� ���׸�Ʈ Ʈ������ �� ��° ������ �� ��ȣ�� �ִ� ������ �� ��° ������ ���� �� �ּڰ��� Ȯ����
�� ��° ������ ���� ���� ���� �ִ� ���� �� ��° ������ ������ ���� �������� Ȯ���ϰ� ���� ���´ٸ� �ᱣ���� 1�� �߰��Ѵ�.
�߰��� �������� ���� ���� ���׸�Ʈ Ʈ���� ������Ʈ���ش�.
�̸� �ݺ��� ���� �ᱣ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��, �׸��� �˰���, ����

��ó : BkOI 2004 2��
*/

int a[SZ][3], seg[SZ * 2]; //���׸�Ʈ Ʈ������ 2��° ���� �ش� ������ ���� 3��° ���� �ּڰ��� ����ִ´�.

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int fs, int fe, int ss, int se, int d) {
    if (ss > fe || se < fs) return SZ + 1;
    else if (ss >= fs && se <= fe) return seg[d];
    return small(find(fs, fe, ss, (ss + se) >> 1, d << 1), find(fs, fe, ((ss + se) >> 1) + 1, se, (d << 1) + 1));
}

void update(int p, int x) {
    seg[p + SZ] = x;
    for (int i = ((p + SZ) >> 1); i >= 1; i >>= 1) {
        seg[i] = small(seg[i << 1], seg[(i << 1) + 1]);
    }
}

int main(void) {
    int n, x, b, c = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x][0] = i; //�Է��� ��ȣ������ �����Ѵ�.
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x][1] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x][2] = i;
    }
    qsort(a + 1, n, sizeof(int) * 3, cmp1);
    for (int i = 1; i <= SZ + n; i++) {
        seg[i] = SZ + 1; //���׸�Ʈ Ʈ���� �ʱⰪ�� ������ �ִ񰪺��� ũ�� �����Ѵ�.
    }

    for (int i = 1; i <= n; i++) {
        b = find(1, a[i][1] - 1, 0, SZ - 1, 1);
        if (b > a[i][2]) c++; //1, 2, 3��° ���� ��� ���� ���� �ִ� ���
        update(a[i][1], a[i][2]);
    }
    printf("%d", c);
    return 0;
}