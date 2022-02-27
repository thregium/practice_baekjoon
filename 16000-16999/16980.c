#include <stdio.h>

/*
���� : H * W(H, W <= 3000) ũ���� ���ڿ� 'J', 'O', 'I'�� ���� �ִ�.
���� �ٸ� (i, j, k, l)(1 <= i < k <= H)(1 <= j <= l <= W)�� ����
'J'�� (i, j), 'O'�� (i, l), 'I'�� (k, j)�� �ִ� �������� ������ ���Ѵ�.

�ذ� ��� : 'O'�� 'I'�� 'J'�� ������ ���� �ֱ� ������,
'J'���� ������ 'O'�� 'I' ������ ���ؼ� ���� ���� �� �ִ�.
������������ 'O' ������ �Ʒ��������� 'I' ������ ���� ���� �̿���
���� �̸� ���صθ� �� ������ ������ ã�� �� �ִ�.

�ֿ� �˰��� : ����, ���շ�, ���� ��

��ó : JOI 2019 1��
*/

char s[3072][3072];
short icnt[3072][3072], ocnt[3072][3072];

int main(void) {
    int h, w;
    long long r = 0;
    scanf("%d %d", &h, &w);
    for (int i = 1; i <= h; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= w; j++) {
            if (s[i][j] == 'I') icnt[i][j] = 1;
            else if (s[i][j] == 'O') ocnt[i][j] = 1;
        }
    }
    for (int i = 1; i <= w; i++) {
        for (int j = h - 1; j > 0; j--) icnt[j][i] += icnt[j + 1][i];
    }
    for (int i = 1; i <= h; i++) {
        for (int j = w - 1; j > 0; j--) ocnt[i][j] += ocnt[i][j + 1];
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (s[i][j] != 'J') continue;
            r += (long long)ocnt[i][j + 1] * icnt[i + 1][j];
        }
    }
    printf("%lld\n", r);
    return 0;
}