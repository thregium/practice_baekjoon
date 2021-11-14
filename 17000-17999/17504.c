#include <stdio.h>

/*
���� : N(N <= 15)���� �м��� �̷���� ���� �м��� Ǭ ����� 1���� �� ���� ���Ѵ�.
�� �м� ���� �ڿ����� 1 �̻� 9 ���Ϸ� �־�����.

�ذ� ��� : �� �ؿ������� ��������� ������ ä��������. �и�� ����, �����÷ο� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : ��ϴ� 2019 I��
*/

int a[16];

void swap(long long* a, long long* b) {
    long long c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int n;
    long long ru = 0, rd = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ru = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        swap(&ru, &rd);
        ru += rd * a[i];
    }
    swap(&ru, &rd);
    ru = rd - ru;
    printf("%lld %lld", ru, rd);
    return 0;
}