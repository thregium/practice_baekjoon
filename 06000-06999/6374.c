#include <stdio.h>

/*
���� : N * N(N <= 100) ũ���� �迭���� Ư���� ���簢�� �κ��� ���� ���� ū ���� ���Ѵ�.

�ذ� ��� : X���� �ּ�, �ִ� ���� ������Ų �� Y���� ������� ���󰡸� �ش��ϴ� X���� �ּ�, �ִ� ������
Y���� �ּڰ��������� ��� �ִ񰪿� ���� ���� ���� �� �ְ�, �׷��� ��� ��츦 Ȯ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : GNY 2001 H��
*/

int a[128][128];

int main(void) {
    int n, s, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int ii = i; ii < n; ii++) {
                s = 0;
                for (int y = j; y < n; y++) {
                    for (int x = i; x <= ii; x++) {
                        s += a[x][y];
                    }
                    if (s > best) best = s;
                }
            }
        }
    }
    printf("%d", best);
    return 0;
}