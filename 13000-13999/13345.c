#include <stdio.h>

/*
���� : ���簢���� �� ���� �־��� ��, ������ �� ���� ��ġ�� ���Ѵ�.

�ذ� ��� : ������ �̿��� ������ ���� Ȯ���ϰ�, �� ���� ���� ���ֺ��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ������

��ó : BAPC 2016P C��
*/

int main(void) {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d%d %d%d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if ((x1 - x3) * (x2 - x3) == -(y1 - y3) * (y2 - y3)) printf("%d %d", x1 + x2 - x3, y1 + y2 - y3);
    else if ((x1 - x2) * (x3 - x2) == -(y1 - y2) * (y3 - y2)) printf("%d %d", x1 + x3 - x2, y1 + y3 - y2);
    else if ((x2 - x1) * (x3 - x1) == -(y2 - y1) * (y3 - y1)) printf("%d %d", x2 + x3 - x1, y2 + y3 - y1);
    else return 1;
    return 0;
}