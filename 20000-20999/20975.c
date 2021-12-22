#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 20)���� �ڿ���(<= 10^9)�� �̷���� ������ �־�����. �� ������ ������ ���Ƿ� �ٲپ�
������ ��� ���� �����ϴ� �� ��° ������ �� ���ϰ� �ǵ��� �ϴ� ����� ���� ���Ѵ�.

�ذ� ��� : ù ��° ������ �� ���� ���� ���� ������ �� ��° ������ ������ ���� ����Ѵ�.
�� ����, �̸� ������������ �����ϸ� ���� ��Ī�� ���� ������ �������� ���� �Ǵµ�, ��Ī�� �� ���� ����
��Ī�� �� ���� ���� ��� ��Ī�� �����ϹǷ� �� ���� (���� ������ ��Ī �� - �տ��� �ߴ� ��Ī ��) ��ŭ�� ��Ī�� �����ϴ�.
����, �� ������ ������ ��Ī�� ���� ���� ���� �ȴ�.

�ֿ� �˰����� : ����, ���շ�, �׸��� �˰�����

��ó : USACO 2021J B3��
*/

int a[32], b[32], c[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] <= b[j]) c[i]++;
        }
    }
    qsort(c, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        r *= (c[i] - i);
    }
    printf("%lld", r);
    return 0;
}