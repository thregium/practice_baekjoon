#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���ǿ� M(M <= 100)�� ���ϸ����� ���� ��, �� ���ϸ����� ���� ���� ������ ������
������ ���Ѵ�. �� ���ǿ��� L(L <= 100)���� ���� ��û�ڿ� D(D <= 100)���� ���� �ڸ��� �־�����.
�� ���� ��û���� ��û ���ϸ���(<= 36)�� �� �� �ִ�. ���ϸ����� �ٸ� ����� ���� �� �켱���� �ִ�.
���� ��û�ÿ��� �ݵ�� ���ϸ����� 1 �̻� �־�� �Ѵ�.

�ذ� ��� : �� ���Ǹ��� D�� L���� ũ�ٸ� 1��ŭ�� ���ϸ����� �־ �ȴ�. �� ���� ��쿡��
���ϸ����� ���� ������ D���� ����� ���ϸ�����ŭ ������ �ȴ�. �̸� �̿��� ��� ������ �ʿ��� ���ϸ�����
������ ����, ���� �ʿ��� �� ���� ������� ��û�ؼ� ������ ������ ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ������ 2016 A��
*/

int a[128], b[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, l, d, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &d);
        for (int i = 0; i < l; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, l, sizeof(int), cmp1);
        if (d > l) b[i] = 1;
        else b[i] = a[d - 1];
    }
    qsort(b, n, sizeof(int), cmp2);
    for (int i = 0; i < n; i++) {
        if (b[i] <= m) {
            m -= b[i];
            r++;
        }
    }
    printf("%d", r);
    return 0;
}