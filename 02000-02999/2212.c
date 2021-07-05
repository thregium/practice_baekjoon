#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10000)���� ���� �̷���� ������ K(K <= 1000)���� �������� ���� ��, ���� ������ ������ ���� ���� ���� ���� ���� ���� ���Ѵ�.
��, ������ ���̴� 0�� �� �� �ִ�.

�ذ� ��� : ���� ������ �� �������� �����ٸ� ������ �������� �� �������� ������ �� �� ���� �Ÿ� �� �ϳ��� ���ܽ�Ű�� ���� ����������.
�� �� ���� �� ���� ���ܽ�Ű�� ���� ���� ���� ���� �� �� �ְ�, �����ϰ� �̸� �ݺ��ϸ� K - 1���� ���� �� �������� ���ܽ�Ű�� ����
���� ����. ����, ���� ������ ���� �� �� ������ �Ÿ��� ã�� �ٽ� ������ �� ���� ū K - 1���� ������ �Ÿ��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : Seoul 2005I E��
*/

int a[10240], b[10240];

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
    int n, k, r = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i + 1] - a[i];
        r += b[i];
    }
    qsort(b, n - 1, sizeof(int), cmp2);
    for (int i = 0; i < k - 1; i++) {
        r -= b[i];
    }
    printf("%d", r);
    return 0;
}