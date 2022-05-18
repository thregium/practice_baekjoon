#include <stdio.h>

/*
���� : N(N <= 10^6)���� �ڿ���(<= 10^9)�� �̷���� �������� �� ������ ���� �� ������ ������ ���ʰ� ��������
�� ��� ���� ū ���� ���� ���Ѵ�.

�ذ� ��� : ���ʰ� �����ʺ����� ���� �ִ��� ���� ���ϸ� �� ������ ���� �ִ��� ���� �ȴ�.

�ֿ� �˰��� : DP?

��ó : JPOI 2011 1-1��
*/

int hilo[1048576][2];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &hilo[i][1]);
        hilo[i][0] = hilo[i - 1][0];
        if (hilo[i][1] > hilo[i][0]) hilo[i][0] = hilo[i][1];
    }
    for (int i = n; i >= 1; i--) {
        if (hilo[i + 1][1] > hilo[i][1]) hilo[i][1] = hilo[i + 1][1];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", hilo[i][0], hilo[i][1]);
    }
    return 0;
}