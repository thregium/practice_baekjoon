#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� �ڿ���(<= 10^9)�� �̷���� �迭���� � ���� �ٸ� �� ���� ���� X(X <= 10^9)�� ���� �ʴ�
���� ū �κ������� ũ�⸦ ���Ѵ�.

�ذ� ��� : �迭�� ������������ �����ϰ� ������ �� ���� ���� ���Ǹ� �� �� ���� ������ ���ѷ� �̷���� �κ�������
���� ū ���� �ٸ� �� ���� ���� �ȴ�. ����, ���ʺ��� ���ӵ� �� ���� ���� ���Ǹ� X�� �ѱ� ���� ������
������ ũ�⸦ ����ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, ����

��ó : BAPC 2018 A��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, r = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] + a[i - 1] > x) break;
        r++;
    }
    printf("%d", r);
    return 0;
}