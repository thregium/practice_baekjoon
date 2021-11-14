#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 20)���� �ڿ���(1, 2, 3, 4, 5)�� �־��� ��, �� �ڿ����� 2���� ����� ���ϴ� ���� �ݺ��� ���� �� �ִ�
���� ū ���� ���Ѵ�.

�ذ� ��� : ���� ������ ����� ���� ������ ���� �����̴�. ����, ������������ ������ �� �迭���� ����� ���س�����
������ ���� ���ϸ� �װ��� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ����

��ó : COCI 17/18#7 1��
*/

double num[32];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num[i]);
    }
    qsort(num, n, sizeof(double), cmp1);
    for (int i = 1; i < n; i++) {
        num[i] = (num[i - 1] + num[i]) / 2;
    }
    printf("%.9f", num[n - 1]);
    return 0;
}