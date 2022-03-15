#include <stdio.h>

/*
���� : N(N <= 100)���� ������ �ְ�, �� ������ M_i(M_i <= 10000)�� ������ �̻��ϵ��� ���� ���� �ִ�.
�� �̻����� ������ ���� ���� ū ������ ���� ���� ������ ���� ���̰� D(D <= 1000) ���ϰ� �Ǿ�� �Ѵ�.
����, �� �̻����� ������ 1000 ������ ���� �ƴ� �����̰�, �̻��ϵ��� ������� ����Ͽ��� �� ��,
��� ������ ��� �̻����� ����� �� �ִ� �� ���Ѵ�.

�ذ� ��� : �� ������ �̻��ϵ� ��� ����� �� �ִ� ���� ã�� ����ϴ� ������ �ݺ��ϸ� �ȴ�.
��� �������� ������ �ִ��� �ٲ� �� �����Ƿ� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�, �׸��� �˰���, ����

��ó : JAG 2009P B��
*/

int miss[128][10240], missc[128], pot[128];

int main(void) {
    int n, d, h, h2, c;
    while (1) {
        scanf("%d %d", &n, &d);
        if (n == 0) break;
        h = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &missc[i]);
            pot[i] = 0;
            for (int j = 0; j < missc[i]; j++) {
                scanf("%d", &miss[i][j]);
                pot[i] += miss[i][j];
            }
            if (pot[i] > h) h = pot[i];
        }
        while (1) {
            c = 0;
            for (int i = 0; i < n; i++) {
                if (missc[i] > 0 && pot[i] - miss[i][missc[i] - 1] >= h - d) {
                    c = 1;
                    pot[i] -= miss[i][missc[i] - 1];
                    missc[i]--;
                    h = 0;
                    for (int j = 0; j < n; j++) {
                        if (pot[j] > h) h = pot[j];
                    }
                    break;
                }
            }
            if (c) continue;
            for (int i = 0; i < n; i++) {
                if (pot[i] != h) continue;
                h2 = 0;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (pot[j] > h2) h2 = pot[j];
                }
                if (missc[i] > 0 && pot[i] - miss[i][missc[i] - 1] >= h2 - d) {
                    c = 1;
                    pot[i] -= miss[i][missc[i] - 1];
                    missc[i]--;
                    h = 0;
                    for (int j = 0; j < n; j++) {
                        if (pot[j] > h) h = pot[j];
                    }
                    break;
                }
            }
            if (!c) break;
        }

        h = 0;
        for (int i = 0; i < n; i++) {
            if (pot[i] > h) h = pot[i];
        }
        printf("%s\n", h ? "No" : "Yes");
    }
    return 0;
}