#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 500000)���� �ڿ���(<= 100)�� �̷���� ������ �־�����. ��� �ڿ����� �� ���� ���븦 �� ������
�ڿ��� ���̴�� �ڸ��� ��� ��� ���� ����� ���� ���� ���Ѵ�. ���븦 �ڸ� ���� �����
�ڸ��� �� �κ� ������ ���̴�.

�ذ� ��� : �ִ��� ���븦 �ұյ��ϰ� �ڸ��� ���� �������� �� �� �ִ�. �̷��� ���� ���� ���� �� ���� �ڸ��� ������,
������������ �����ϰ�, �� ������� �ڸ��� �ȴ�. ��ü ���� �̸� ���ص־� �Ѵ�.

�ֿ� �˰����� : �׸��� �˰�����, ����

��ó : ��� 2018 1��
*/

int a[524288];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long s = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n - 1; i++) {
        s -= a[i];
        r += a[i] * s;
    }
    printf("%lld", r);
    return 0;
}