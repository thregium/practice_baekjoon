#include <stdio.h>

/*
���� : �� ���� ���簢���� �־��� ��, ù ��° ���簢���� �� ��° ���簢���� ���� �������� ���̸� ���Ѵ�.
�� ���簢���� ��ǥ ������ 10000 ������ �ڿ����� �־�����.

�ذ� ��� : �� ���簢���� �������� ���̸� �ּ� ������ ���� �� ù ��° ���簢���� ���̿��� ����.
��, �������� ���̰� ������ ���� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : ������

��ó : Taejeon 2002 A��
*/

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, x1, y1, x2, y2, x3, y3, x4, y4, xl, yl, xh, yh;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        xl = big(x1, x3);
        yl = big(y1, y3);
        xh = small(x2, x4);
        yh = small(y2, y4);
        if (xh < xl || yh < yl) printf("%d\n", (x2 - x1) * (y2 - y1));
        else printf("%d\n", (x2 - x1) * (y2 - y1) - (xh - xl) * (yh - yl));
    }
    return 0;
}