#include <stdio.h>
#include <math.h>

/*
���� : ���� �����ϴ� �簢���� �� ���� �־��� ��, �� ���� ���� ��� �ϳ��� ���� ������ ���ٸ�
�׷��� �簢���� ���� �� �ִ��� ���ϰ�, �����ϴٸ� ������ �� ���� ���̸� ����Ѵ�.
�Ұ����� ��� -1�� ����Ѵ�.

�ذ� ��� : ���� ������ �ٸ� �� ������ �̷���� �ﰢ���� �����ﰢ���Ӱ�
�밢���� ���� ���ֺ��� �� ���� ���� �հ� ������ �̿��Ѵ�.

�ֿ� �˰����� : ������, ����

��ó : �泲�� 3ȸ E��
*/

int main(void) {
    int a, b, c, d, p, q, r;
    double x;
    scanf("%d %d %d", &a, &b, &c);
    p = a;
    q = 2 * b * c;
    r = a * (c * c - a * a + b * b);
    d = q * q - 4 * p * r;
    if (d < 0) {
        printf("%d", -1);
        return 0;
    }
    x = (-q + sqrt(d)) / (2 * p);
    if (x < 0) {
        printf("%d", -1);
        return 0;
    }
    printf("%d", (int)(x + 0.000001));
}