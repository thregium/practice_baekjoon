#include <stdio.h>

/*
���� : R * C(R, C <= 1000) ũ���� ���ڿ��� �� ĭ���� ���(<= 1000, �ڿ���)�� �־�����.
Q(Q <= 100000)���� ���簢�� ������ ���� ��� ����� ���� ���Ѵ�. �Ҽ��� �Ʒ��� �����Ѵ�.

�ذ� ��� : 2���� ���� ���� ���� ��� ���� ���� ���� ���̷� ������ ����� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���� ��

��ó : �泲�� 2ȸ E��
*/

int psum[1024][1024];

int getsum(int x1, int y1, int x2, int y2) {
    return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
}

int main(void) {
    int r, c, q, x1, y1, x2, y2;
    scanf("%d %d %d", &r, &c, &q);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &psum[i][j]);
            psum[i][j] += psum[i][j - 1];
        }
    }
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) psum[j][i] += psum[j - 1][i];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", getsum(x1, y1, x2, y2) / ((x2 - x1 + 1) * (y2 - y1 + 1)));
    }
    return 0;
}