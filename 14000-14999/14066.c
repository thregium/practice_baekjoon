#include <stdio.h>

/*
���� : M * N(M, N <= 50) ũ���� ĭ�鿡 �ڽ����� A_ij(A_ij <= 50)���� �׿��ִ�.
�� ����� �׸����� �׷� ����Ѵ�.

�ذ� ��� : �� ���ڵ��� ��->��, ����->������, ��->�� ������� ���׸��ϸ鼭 ���� �ȴ�.
��ǥ ó���� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : CPC 2016 D��
*/

int a[64][64];
char res[1024][1024];
const char* box[6] = { "..+---+", "./   /|", "+---+ |", "|   | +", "|   |/.", "+---+.." };

int main(void) {
    int m, n, x, y, xl = 1024, yl = 1024, xh = -1, yh = -1;
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) res[i][j] = '.';
    }
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            for (int k = 0; k < a[i][j]; k++) {
                x = 512 + i * 2 - k * 3;
                y = 512 + j * 4 - i * 2;
                if (x > xh) xh = x;
                if (x - 5 < xl) xl = x - 5;
                if (y < yl) yl = y;
                if (y + 6 > yh) yh = y + 6;
                for (int ii = 0; ii < 6; ii++) {
                    for (int jj = 0; jj < 7; jj++) {
                        if (box[ii][jj] != '.') res[x + ii - 5][y + jj] = box[ii][jj];
                    }
                }
            }
        }
    }

    if (xh < 0) return 1;
    for (int i = xl; i <= xh; i++) {
        for (int j = yl; j <= yh; j++) printf("%c", res[i][j]);
        printf("\n");
    }
    return 0;
}