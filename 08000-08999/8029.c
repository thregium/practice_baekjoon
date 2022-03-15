#include <stdio.h>

/*
���� : N * N(N <= 250) ũ���� 0�� 1�� ���� �迭���� �� ĭ�� ���� Rĭ�� �迭��
���� ���� ���� ���� ���� ����Ѵ�.

�ذ� ��� : ���ѽð��� ��� ������ ���� ���� ���ϴ��� �ð� ���� ���� �� �ִ�.
�迭�� ������ ����� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : POI 2000/2001_1 3��
*/

int a[256][256];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, r, s;
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s = 0;
            for (int ii = big(0, i - r); ii <= small(n - 1, i + r); ii++) {
                for (int jj = big(0, j - r); jj <= small(n - 1, j + r); jj++) s += a[ii][jj];
            }
            printf("%d ", s);
        }
        printf("\n");
    }
    return 0;
}