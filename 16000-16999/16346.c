#include <stdio.h>

/*
���� : N(N <= 300000)���� ������ ��ǥ���� �ִ�. �� ������ ��ġ�� 0 �̻� 5000 ������ �����̴�.
�̶�, Q(Q <= 300000)���� �������� ���������� ���� ����� �Ÿ��� ���Ѵ�.
�� ������ �����¿�밢������ �̵� �����ϴ�.

�ذ� ��� : �� ������ �Ÿ����� ���� ������ ���¸� Ȯ���ϸ� ���簢�� ���°� �ȴ�.
����, �� ������ 2���� ���� ���� ���� ����, �� �������� 0���� 5000 ������ ���� ���� �̺� Ž������
������ �ִ� ���� ���� �Ÿ��� ���ϴ� ������� O(Q*log(MaxX))�� �ð��� ���� ã�� �� �ִ�.
����� ũ�� ������ �����Ѵ�.

�ֿ� �˰��� : ���� ��, �Ķ��Ʈ��

��ó : CTU 2018 S��
*/

int psum[5120][5120];

int getsum(int x1, int y1, int x2, int y2) {
    if (x1 == 0) {
        if (y1 == 0) return psum[x2][y2];
        else return psum[x2][y2] - psum[x2][y1 - 1];
    }
    else {
        if (y1 == 0) return psum[x2][y2] - psum[x1 - 1][y2];
        else return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
    }
}

int main(void) {
    int n, q, x, y, xl, yl, xh, yh, lo, hi, mid;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d  %d", &x, &y);
        psum[x][y]++;
    }
    for (int i = 0; i <= 5000; i++) {
        for (int j = 1; j <= 5000; j++) psum[i][j] += psum[i][j - 1];
    }
    for (int i = 0; i <= 5000; i++) {
        for (int j = 1; j <= 5000; j++) psum[j][i] += psum[j - 1][i];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &y);
        lo = 0, hi = 5000;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            xl = x - mid, yl = y - mid, xh = x + mid, yh = y + mid;
            if (xl < 0) xl = 0;
            if (yl < 0) yl = 0;
            if (xh > 5000) xh = 5000;
            if (yh > 5000) yh = 5000;
            if (getsum(xl, yl, xh, yh)) hi = mid;
            else lo = mid + 1;
        }
        printf("%d\n", lo);
    }
    return 0;
}