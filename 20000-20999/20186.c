#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 5000)���� �ڿ���(<= 100000)���� �־��� ��, �ش� �ڿ��� ��� K(K <= N)���� �̴� ��� ���
���� ������ ū ���� ����. ������ �� ���� ���� ���� ������ ���̰�, �� ���� ������ �ش� ������ ���� �� ���
�̹� ���� ���� �� ���� ����.

�ذ� ��� : ���ʿ��� �̹� ���� ���� ��� ���� �̵� K�� ���� �������� �� �� �ִ�.
����, ���� ū ������ �����ϸ� �׻� ������ �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ���� 2020_2 ��1��
*/

int a[5120];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < k; i++) {
        r += a[i];
    }
    r -= k * (k - 1) / 2;
    printf("%lld", r);
    return 0;
}