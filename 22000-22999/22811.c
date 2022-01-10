#include <stdio.h>

/*
���� : W * H(W, H <= 100) ũ���� ���� ���� �� N(N <= 500)���� �������� �ɾ��� �ִ�. S * T ũ���� ���簢�� ���
�������� ���� ���� ���簢������ �������� �� �� �ִ� �� ���Ѵ�.

�ذ� ��� : W�� H�� ũ�Ⱑ �۱� ������ ��� ������ ���簢���� ���� ������ ���� �������� ������ ���س����� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JDC 2003 B��
*/

int pers[128][128];

int main(void) {
    int n, w, h, s, t, r, cnt;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d %d", &w, &h);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &s, &t);
            pers[s][t]++;
        }
        scanf("%d %d", &s, &t);

        r = 0;
        for (int i = 1; i <= w - s + 1; i++) {
            for (int j = 1; j <= h - t + 1; j++) {
                cnt = 0;
                for (int ii = i; ii < i + s; ii++) {
                    for (int jj = j; jj < j + t; jj++) cnt += pers[ii][jj];
                }
                if (cnt > r) r = cnt;
            }
        }
        printf("%d\n", r);

        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) pers[i][j] = 0;
        }
    }
    return 0;
}