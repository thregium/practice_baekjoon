#include <stdio.h>

/*
���� : N(N <= 1000)���� �ڿ����� �̷���� ������ ���� ��, �� �������� �� ���� ���� ����� ���� ��������
���� �� ������ ���� ���� ���̸� ���Ѵ�.

�ذ� ��� : N�� ����� �۱� ������ ��� ���� �ѹ��� �������� ������ ���� ���� ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2012O B1��
*/

int want[1024], wnew[1024];

int main(void) {
    int n, wp, c, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &want[i]);
    }
    for (int i = 0; i < n; i++) {
        wp = 0;
        for (int j = 0; j < n; j++) {
            if (want[j] != want[i]) wnew[wp++] = want[j];
        }
        c = 1;
        for (int j = 1; j < wp; j++) {
            if (wnew[j] == wnew[j - 1]) c++;
            else c = 1;
            if (c > r) r = c;
        }
    }
    printf("%d", r);
    return 0;
}