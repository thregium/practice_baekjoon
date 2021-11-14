#include <stdio.h>

/*
���� : N * M(N, M <= 50) ũ���� ���簢���� �� ĭ�鿡 ���ڵ��� ���� �ִ�. �� ���簢���� 3���� ���簢������ ������
�� ĭ�� ���� ���ڵ��� ���� ���� �ִ밡 �� ���� �� ���� ���Ѵ�.

�ذ� ��� : ���Ʈ ������ ���� ��ü ���簢���� 3���� ������ ��� ����� �õ��ϰ� �׵� ��� ���� ū ���� ���Ѵ�.
��ü ���簢���� ��������� ������ ���� ����.

�ֿ� �˰��� : ���Ʈ ����, ���
*/

char s[64][64];

int big(int a, int b) {
    return a > b ? a : b;
}

long long track(int n, int xl, int xh, int yl, int yh) {
    long long r = 0;
    if (n == 1) {
        for (int i = xl; i <= xh; i++) {
            for (int j = yl; j <= yh; j++) r += s[i][j] - '0';
        }
        return r;
    }

    for (int i = xl; i < xh; i++) {
        if (n == 3) {
            r = big(r, track(1, xl, i, yl, yh) * track(2, i + 1, xh, yl, yh));
            r = big(r, track(2, xl, i, yl, yh) * track(1, i + 1, xh, yl, yh));
        }
        else r = big(r, track(1, xl, i, yl, yh) * track(1, i + 1, xh, yl, yh));
    }
    for (int i = yl; i < yh; i++) {
        if (n == 3) {
            r = big(r, track(1, xl, xh, yl, i) * track(2, xl, xh, i + 1, yh));
            r = big(r, track(2, xl, xh, yl, i) * track(1, xl, xh, i + 1, yh));
        }
        else r = big(r, track(1, xl, xh, yl, i) * track(1, xl, xh, i + 1, yh));
    }
    return r;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    printf("%lld", track(3, 0, n - 1, 0, m - 1));
    return 0;
}