#include <stdio.h>

/*
���� : ���� �� ���� �־��� ��, �� ���� ������ �ִ��� ���Ѵ�. �� ���� ��ǥ�� 1 �̻� 1000 ������ ������ �����ȴ�.

�ذ� ��� : CCW �˰����� �̿��Ѵ�.

�ֿ� �˰��� : ������, CCW
*/

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int main(void) {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (ccw(x1, y1, x2, y2, x3, y3)) printf("WINNER WINNER CHICKEN DINNER!");
    else printf("WHERE IS MY CHICKEN?");
    return 0;
}