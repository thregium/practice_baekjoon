#include <stdio.h>

/*
���� : ��ȭ�� ������ ��뷮�� ���� �־��� ��, 3���� ����� �� ���� �� ������� �������� ���� ����� ���Ѵ�.

�ذ� ��� : 3���� ������� ����� ����� ���� ���� �� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : Tehran 2017 A��
*/

int main(void) {
    int c, d, x, y, z;
    while (1) {
        scanf("%d %d", &c, &d);
        if (c == 0 && d == 0) break;
        x = c * 30 + d * 40;
        y = c * 35 + d * 30;
        z = c * 40 + d * 20;
        if (x <= y && x <= z) printf("%d\n", x);
        else if (y <= x && y <= z) printf("%d\n", y);
        else printf("%d\n", z);
    }
    return 0;
}