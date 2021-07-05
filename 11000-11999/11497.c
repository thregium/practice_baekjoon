#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10000)���� ���� �������� ��ġ�� ��, ������ �� ���� ���� ���� ���� �Ѵٸ� �� ���� ������ ���Ѵ�.

�ذ� ��� : �׷��� ��ġ�ϴ� ����� �� ���� ���� ���� ���� ���� ��, �������� ���� ���� ū ���� ��ġ�ϴ� ����̴�.
�̸� �迭�� ǥ���ϸ� ���ĵ� �迭���� �� ĭ�� �̵��ϴ� �Ͱ� ������ �� �� �ְ�, ���� ���ĵ� �迭���� 2ĭ ������ ���� �� ��
���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : Daejeon 2015 E��
*/

int l[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &l[i]);
        }
        qsort(l, n, sizeof(int), cmp1);
        r = 0;
        for (int i = 2; i < n; i++) {
            if (l[i] - l[i - 2] > r) r = l[i] - l[i - 2];
        }
        printf("%d\n", r);
    }
    return 0;
}