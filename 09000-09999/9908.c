#include <stdio.h>

/*
���� : R(R <= 40) * C(C <= 20) ũ���� ���簢������ N(N < 100)���� ������ ���Ե��� �ʴ�
���� ���� ������ ���簢���� ���̸� ���Ѵ�.

�ذ� ��� : R�� C�� ������ �۱� ������ ���Ʈ ������ ��� ��츦 ���캸�� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : NOIS 2002 2��
*/

int a[64][64];

int main(void) {
    int r, c, n, x, y, t, res = 0;
    scanf("%d %d", &r, &c);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            for (int ii = i; ii <= r; ii++) {
                for (int jj = j; jj <= c; jj++) {
                    t = 0;
                    for (int iii = i; iii <= ii; iii++) {
                        for (int jjj = j; jjj <= jj; jjj++) t |= a[iii][jjj];
                    }
                    if (!t && (ii - i + 1) * (jj - j + 1) > res) res = (ii - i + 1) * (jj - j + 1);
                }
            }
        }
    }

    printf("%d", res);
    //if (r == 6 && c == 10) return 1;
    return 0;
}