#include <stdio.h>

/*
���� : P���� H���� �ֵ��׸� �Ծ��� ��, 1�δ� ��� � ���� �������� ���Ѵ�.

�ذ� ��� : H / P���̹Ƿ� �̸� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : Latin 2012 PA��
*/

int main(void) {
    double h, p;
    while (scanf("%lf %lf", &h, &p) != EOF) {
        printf("%.2f\n", h / p);
    }
    return 0;
}