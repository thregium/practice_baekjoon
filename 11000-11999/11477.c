#include <stdio.h>

/*
���� : R * C(R, C <= 100) ũ���� ���ڿ� 1000 ������ �ڿ����� �����ִ�. �� ĭ���� �� ĭ��
�����¿� 4 ���� �� �� �������� �̾��� ĭ�� ��� �� ĭ�� ������ ���� ���� �ִ� ������ ���� ���� ���Ѵ�.

�ذ� ��� : �� ĭ���� �� ������ ĭ�鿡 ���� �ִ��� ���ϰ�,
�� �ִ��� �ش� ĭ�� ������ ���� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : NEERC 2015N L��
*/

int a[128][128];

int main(void) {
    int r, c, hi, res = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            hi = 0;
            for (int k = 0; k < i; k++) {
                if (a[k][j] > hi) hi = a[k][j];
            }
            if (hi < a[i][j]) res++;
            hi = 0;
            for (int k = i + 1; k < r; k++) {
                if (a[k][j] > hi) hi = a[k][j];
            }
            if (hi < a[i][j]) res++;
            hi = 0;
            for (int k = 0; k < j; k++) {
                if (a[i][k] > hi) hi = a[i][k];
            }
            if (hi < a[i][j]) res++;
            hi = 0;
            for (int k = j + 1; k < c; k++) {
                if (a[i][k] > hi) hi = a[i][k];
            }
            if (hi < a[i][j]) res++;
        }
    }
    printf("%d", res);
    return 0;
}