#include <stdio.h>

/*
���� : N(N <= 10)���� ���������� ���� ���� ������ ���̵��� �־��� ��, K(K <= 14)���� ������ ������ �־��� �������
���� ���� ��������� ���̵��� ���� ���Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. �迭�� ���� ó���� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : NEERC 2015 E��
*/

int prob[16][16];

int main(void) {
    int n, k, x, s = 0, c = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) prob[i][j] = -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            scanf("%d", &prob[i][j]);
        }
    }
    for (int i = 0;; i++) {
        for (int j = 0; j < n; j++) {
            if (prob[j][i] < 0) {
                c++;
                s += 50;
            }
            else if (prob[j][i] >= s) {
                c++;
                s += prob[j][i];
            }
            if (c >= k) break;
        }
        if (c >= k) break;
    }
    printf("%d", s);
    return 0;
}