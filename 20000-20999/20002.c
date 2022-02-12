#include <stdio.h>

/*
���� : N * N(N <= 300) ũ���� ���ڿ��� �ش� ĭ�� ����(|| <= 1000)�� �־�����.
�̶�, ���簢�� ���� ��� ������ ���� ū ������ ���Ѵ�. ��, ������ 0�� ���� ����.

�ذ� ��� : 2���� ���� ���� �̸� ���صθ� �� ���簢�� ���������� ������ O(1)�� ���� �� �ִ�.
���簢�� ������ ������ O(N^3)�̹Ƿ� ��� ���簢�� �������� ������ ���� ������ ���ؼ� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ���� ��

��ó : �泲�� 4ȸ B��
*/

int psum[384][384];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int getsum(int x1, int y1, int x2, int y2) {
    return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
}

int main(void) {
    int n, r = -103000;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &psum[i][j]);
            psum[i][j] += psum[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) psum[j][i] += psum[j - 1][i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= small(n - i + 1, n - j + 1); k++) {
                r = big(r, getsum(i, j, i + k - 1, j + k - 1));
            }
        }
    }
    printf("%d", r);
    return 0;
}