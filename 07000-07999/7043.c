#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 25000)���� ������ �־��� ��, ���Ͽ� 1���� T(T <= 10^6)���� ��� �ڿ����� �����ϴ� ������ ���� �� �ִ��� Ȯ���ϰ�,
�ִٸ� �׷��� �� ��� �����ϴ� ������ ���� ���� ���� ���� ���� ����Ѵ�. ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : �� �������� �������� �������� ������ ����, �Ź� ���� ���������� �� �� �ִ� �� ���������� ��� ���� ���
���� ������ �ڿ� �ִ� ������ ã�´�. �׸��� �� ������ ��� ���� ���� 1�� ���ϰ� ���� + 1�� ���ο� �������� ���������� ���Ѵ�.
�� ������ T�� �� �� �Ǵ� ��� ������ Ȯ���� �� ���� �̸� �ݺ��Ѵ�.
���� T�� �������� �������� ���ο� ������ ã�� �� ���ٸ� T���� �� �� �����Ƿ� -1�� ����Ѵ�. �Ǵ� ��� ������ Ȯ���ϰ���
T�� �������� ���� ��쵵 ���������� -1�� ����Ѵ�. �� �ܿ��� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, ����

��ó : USACO 2004D S1��
*/

int a[25600][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0, t, p = 0, l = 1, lb;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    while (p < n && l <= t) {
        lb = -1;
        while (p < n && a[p][0] <= l) {
            if (a[p][1] > lb) lb = a[p][1];
            p++;
        }
        if (lb < 0) {
            r = -1;
            break;
        }
        r++;
        l = lb + 1;
    }
    if (l <= t) r = -1;
    printf("%d", r);
    return 0;
}