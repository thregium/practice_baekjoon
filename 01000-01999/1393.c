#include <stdio.h>
#include <stdlib.h>

/*
���� : (Xe, Ye)���� (dX, dY)�������� �̵��ϴ� ���� (Xs, Ys)������ �Ÿ��� ���� ª������
���������� ��ġ�� ���Ѵ�. ���� ������ ��츸 �־�����, ��� ���� ���� 100 ������ �����̴�.

�ذ� ��� : ��Ŭ���� ȣ�������� dx�� dy�� gcd�� ���� �� dx, dy�� ���� gcd�� ������.
�� �� ��ǥ ������ �����Ƿ� ��� ���� ���캸�� ���� �������� ���������� �Ÿ��� �� �־����� ������
�Ÿ��� ���ؼ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ŭ���� ȣ����, ���Ʈ ����

��ó : xhark
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int getdist(int xs, int ys, int xe, int ye) {
    return (ye - ys) * (ye - ys) + (xe - xs) * (xe - xs);
}

int main(void) {
    int xs, ys, xe, ye, dx, dy, g;
    scanf("%d %d%d %d %d %d", &xs, &ys, &xe, &ye, &dx, &dy);
    if (dx == 0 && dy == 0) {
        printf("%d %d", xe, ye);
        return 0;
    }
    g = gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
    for (int i = 0;; i++) {
        if (getdist(xs, ys, xe + dx * i, ye + dy * i) <=
            getdist(xs, ys, xe + dx * (i + 1), ye + dy * (i + 1))) {
            printf("%d %d", xe + dx * i, ye + dy * i);
            return 0;
        }
    }
    return 1;
}