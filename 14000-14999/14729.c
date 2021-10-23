#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10^7)���� �Ǽ�(�Ҽ��� �Ʒ� 3�ڸ�, 0 �̻� 100 ����)�� �־��� ��,
���� ���� 7���� �Ǽ��� �Ҽ��� �Ʒ� 3�ڸ����� ����Ѵ�. (���ѽð� 10��)

�ذ� ��� : �� �Ǽ����� ������������ ������ ����, �տ������� 7���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : �߾Ӵ� 2017P D��
*/

double score[10485760];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &score[i]);
    }
    qsort(score, n, sizeof(double), cmp1);
    for (int i = 0; i < 7; i++) {
        printf("%.3lf\n", score[i]);
    }
    return 0;
}
