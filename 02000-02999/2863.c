#include <stdio.h>

/*
���� : �� ���� �־��� ��, �� ���� �������� ���� �� �ִ� �м��� �� ��� �� �� ������ ���� ���� ū�� ���Ѵ�.

�ذ� ��� : �� ���� �� ���� ���� �и�� �ϴ� �м��� ����� ����, ������ ���� ���� ���� ū ���� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : COCI 10/11#3 1��
*/

int main(void) {
    int a, b, c, d, best = 0, res = -1;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a * a * b * d + a * b * b * c > best) {
        best = a * a * b * d + a * b * b * c;
        res = 0;
    }
    if (a * b * c * c + a * a * c * d > best) {
        best = a * b * c * c + a * a * c * d;
        res = 1;
    }
    if (a * c * d * d + b * c * c * d > best) {
        best = a * c * d * d + b * c * c * d;
        res = 2;
    }
    if (b * b * c * d + a * b * d * d > best) {
        best = b * b * c * d + a * b * d * d;
        res = 3;
    }
    printf("%d", res);
    return 0;
}