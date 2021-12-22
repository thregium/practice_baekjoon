#include <stdio.h>
#define INF 103000

/*
���� : ��ǥ���� N(1 <= N <= 100000)���� ���� ���� ��ġ(|| <= 10000)�� �־��� ��,
��� ���� �����ϴ� ��ǥ�࿡ ������ ���� ���� ���簢���� ���̸� ���Ѵ�.

�ذ� ��� : X�� Y��ǥ�� �ּ�, �ִ��� ��� �ִٰ�, ���� ���� �� ���� �� ���� �����Ѵ�.
�������� (X��ǥ �ִ� - �ּ�) * (Y��ǥ �ִ� - �ּ�)�� ���� ���� �ȴ�.

�ֿ� �˰��� : ������

��ó : Seoul 2006I A��
*/

int main(void) {
    int n, x, y, xl = INF, xh = -INF, yl = INF, yh = -INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x < xl) xl = x;
        if (x > xh) xh = x;
        if (y < yl) yl = y;
        if (y > yh) yh = y;
    }
    printf("%d", (xh - xl) * (yh - yl));
    return 0;
}