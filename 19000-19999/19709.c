#include <stdio.h>
#include <stdlib.h>

/*
���� : N���� �б��� ���ö��� �������� �Ѵ�. �� �б����� K_i���� ���ö��� �����ų� �ƿ� ������ �ʾƾ� �Ѵٸ�
M���� ���ö����� ���� �� �ִ� �б� ������ �ִ��� ���Ѵ�.

�ذ� ��� : K_i�� ������������ ������ �� �� ������� �ִ��� ������ ���� �õ��Ѵ�.
�׶� ���� �б� ������ ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : NOIS 2016 1��
*/

int k[1030000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &m, &n);
    if (m < 0 || m > 1000000000 || n > 100000) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }
    qsort(k, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (m >= k[i]) {
            m -= k[i];
            r++;
        }
        else break;
    }
    printf("%d", r);
    return 0;
}