#include <stdio.h>
#include <math.h>

/*
���� : N(N <= 20)���� ���������� �̷���� �������� ������ ������ �ѷ��� ���Ѵ�.

�ذ� ��� : 1��° ������ �����ϰ�� ������ �������� �Ÿ� ���� ���� ���Ѵ�. ������ ������ Ȯ���� �Ŀ��� ������ ������
1��° �������� �Ÿ��� ���Ѵ�.

�ֿ� �˰��� : ������, ����

��ó : ���� 2ȸ H��
*/

int main(void) {
    int n, x, y, sx = 0, sy = 0, lx = 0, ly = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (i) {
            r += abs(x - lx) + abs(y - ly);
        }
        else {
            sx = x;
            sy = y;
        }
        lx = x;
        ly = y;
    }
    r += abs(sx - lx) + abs(sy - ly);
    printf("%d", r);
    return 0;
}