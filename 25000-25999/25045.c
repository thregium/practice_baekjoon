#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 200000)���� ���ǰ� M(M <= 200000)���� ���� �ִ�. �� ���� ��������
������ ��ġ - ������ �������� ������ ��, �������� ���� �ִ��� ���Ѵ�.
������ ��ġ�� ������ ������ 10^9 ������ �ڿ����̴�.

�ذ� ��� : ��� ���� ��� ������ ��� ��� ��� ����ǵ� �׻� ������ ���� ���� ���̴�.
�̸� ������ �����Ͽ� ���� ���� ������ ������ ���� ������ �ֵ��� �ϸ� �������� ������ ���� ������ ��
������ ���� �ִ밡 �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : DGIST 2022 B��
*/

int a[204800], b[204800];

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
    int n, m;
    long long r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    qsort(a, n, sizeof(int), cmp2);
    qsort(b, m, sizeof(int), cmp1);
    for (int i = 0; i < m && i < n; i++) {
        if (b[i] > a[i]) break;
        else r += a[i] - b[i];
    }
    printf("%lld", r);
    return 0;
}