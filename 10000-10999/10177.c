#include <stdio.h>

/*
���� : M * M(M <= 5) ũ���� �迭�� �־��� ��, �ش� �迭�� ���������� ���Ѵ�.
��� ��� ��, �밢���� ���� �������� Ȯ���ϸ� �ȴ�.

�ذ� ��� : �迭�� �Է¹ް� �� ��� ��, �밢���� ���� ���� ���ϰ�, ���� ������ Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� ; ����

��ó : PLU 2014N 8��
*/

int sqr[8][8];

int main(void) {
    int t, m, s, as, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &sqr[i][j]);
            }
        }
        as = 0, r = 1;
        for (int i = 0; i < m; i++) {
            s = 0;
            for (int j = 0; j < m; j++) s += sqr[i][j];
            if (i == 0) as = s;
            else if (as != s) r = 0;
            s = 0;
            for (int j = 0; j < m; j++) s += sqr[j][i];
            if (as != s) r = 0;
        }
        s = 0;
        for (int i = 0; i < m; i++) s += sqr[i][i];
        if (as != s) r = 0;
        s = 0;
        for (int i = 0; i < m; i++) s += sqr[i][m - i - 1];
        if (as != s) r = 0;

        if (r) printf("Magic square of size %d\n", m);
        else printf("Not a magic square\n");
    }
    return 0;
}