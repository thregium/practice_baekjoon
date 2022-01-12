#include <stdio.h>

/*
���� : N(N <= 200)���� ���簢���� 0������ ���ʷ� �̹� ���� ���簢���� �����ϰ� �ٿ�������.
���簢���� �ٿ����� �� ���� ���� ���� ������ �־����� ��ü ���¸� �ѷ��δ� ���簢���� ũ�⸦ ���Ѵ�.

�ذ� ��� : �� ���簢���� X�� Y��ǥ�� ������ ����(0�� ���簢���� (0, 0)), �ٿ����� �� ����
X�� Y��ǥ�� �ִ�, �ּڰ��� ������ ������. ���� ���� �� �ִ� - �ּڰ� + 1�� �� ��ǥ�� ������ ����,
�̴� �� ���̿� �ʺ� �ȴ�.

�ֿ� �˰��� : ����

��ó : JDC 2010 A��
*/

int point[256][2];
int dxy[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int main(void) {
    int n, ni, d, xl, yl, xh, yh;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2010\\qualify_judge\\A1", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        xl = 0, yl = 0, xh = 0, yh = 0;
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &ni, &d);
            if (ni >= i) return 1;
            point[i][0] = point[ni][0] + dxy[d][0];
            point[i][1] = point[ni][1] + dxy[d][1];
            if (point[i][0] < xl) xl = point[i][0];
            if (point[i][0] > xh) xh = point[i][0];
            if (point[i][1] < yl) yl = point[i][1];
            if (point[i][1] > yh) yh = point[i][1];
        }
        printf("%d %d\n", yh - yl + 1, xh - xl + 1);
    }
    return 0;
}