#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 1000)���� ���� ��ǥ���� �ִ�. �� ���� ����ġ�� ������ �ִ�. �̶�, A * B ũ���� ���簢�� �ȿ�
�ִ� ���� ����ġ �ִ� - �ּڰ��� �ִ��� ���Ѵ�. �־��� ��� ���� 2 * 10^6 ������ �ڿ����̴�.

�ذ� ��� : ���� ���� ����ġ�� ���� ���� ū ����ġ�� �� 2���� ����, �� �� ���� �����ϴ� ���� ���� ���簢����
A * B �������� Ȯ���Ͽ� �׷��� ��� ��� ���� ū ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����?
*/

int pt[1024][3];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 2);
    int bi = *((int*)b + 2);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, b, xlo, xhi, ylo, yhi, res = 0;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &pt[i][0], &pt[i][1], &pt[i][2]);
    }
    qsort(pt, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            xlo = pt[i][0], xhi = pt[i][0];
            ylo = pt[i][1], yhi = pt[i][1];
            if (pt[j][0] < xlo) xlo = pt[j][0];
            if (pt[j][0] > xhi) xhi = pt[j][0];
            if (pt[j][1] < ylo) ylo = pt[j][1];
            if (pt[j][1] > yhi) yhi = pt[j][1];
            if (xhi - xlo >= a || yhi - ylo >= b) continue;
            if (pt[j][2] - pt[i][2] > res) {
                res = pt[j][2] - pt[i][2];
            }
        }
    }
    printf("%d", res);
    return 0;
}