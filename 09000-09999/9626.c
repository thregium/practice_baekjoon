#include <stdio.h>

/*
���� : M * N(M, N <= 10) ũ���� ũ�ν����� ������ ���� Uĭ, ���� Lĭ, ������ Rĭ, �Ʒ��� D(U, L, R, D <= 5)ĭ��
ü���� ���̷� ä�� ���¸� ����Ѵ�.

�ذ� ��� : (M + U + D) * (N + L + R) ũ���� ü������ ����ϵ�, U����� U + M�� �������� L������ L + N�� ������ ������
�ش��ϴ� ���ڸ� ����Ѵ�. �Ǵ� �� �������� L���� ���� ���ڿ��� ����ϴ� ����� �ִ�.

�ֿ� �˰��� : ����

��ó : COCI 13/14#3 2��
*/

char cw[16][16];

int main(void) {
    int m, n, u, l, r, d;
    scanf("%d %d%d %d %d %d", &m, &n, &u, &l, &r, &d);
    for (int i = 0; i < m; i++) {
        scanf("%s", cw[i]);
    }
    for (int i = 0; i < m + u + d; i++) {
        for (int j = 0; j < n + l + r; j++) {
            if (i >= u && i < u + m && j >= l && j < l + n) {
                if (j == l) printf("%s", cw[i - u]);
                else continue;
            }
            else printf("%c", ((i + j) & 1) ? '.' : '#');
        }
        printf("\n");
    }
    return 0;
}