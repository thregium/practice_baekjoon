#include <stdio.h>
#include <math.h>

/*
���� : �־��� ���� ���簢��(XY��� ������)�� �־��� ��, ���� ���簢���� �Ÿ��� ���Ѵ�. ��, ���� ���簢���� �ٱ��� �ִ�.

�ذ� ��� : ���簢���� ������ �����ϸ� ��ǥ����� 9��(���簢�� ���θ� �����ϸ� 8��)�� ������ ����.
��츦 ������ ������ ���� ���� ���Ѵ�. �밢�� �����̶�� ��Ÿ��� ������ �̿��� ���������� �Ÿ��� ���ϰ�,
�� �����̶�� �ش� ������ x��ǥ �Ǵ� y��ǥ ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : ������, ���̽� ��ũ

��ó : PacNW 2018 G/T�� // MidC 2018 F�� // SEUSA 2018D2 B��
*/

double getdist(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(void) {
    int x, y, x1, y1, x2, y2;
    scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);
    if (x < x1 && y < y1) printf("%lf", getdist(x, y, x1, y1));
    else if (x < x1 && y > y2) printf("%lf", getdist(x, y, x1, y2));
    else if (x > x2 && y < y1) printf("%lf", getdist(x, y, x2, y1));
    else if (x > x2 && y > y2) printf("%lf", getdist(x, y, x2, y2));
    else if (x < x1) printf("%d", x1 - x);
    else if (x > x2) printf("%d", x - x2);
    else if (y < y1) printf("%d", y1 - y);
    else if (y > y2) printf("%d", y - y2);
    return 0;
}