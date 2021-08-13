#include <stdio.h>

/*
���� : 2014�� 4�� 2�Ϻ��� ������ N(N <= 10000)���� �Ǵ� ���� �������� ���Ѵ�.

�ذ� ��� : N�� ���� ���̹Ƿ� N�ϰ��� �������� ���� �ùķ��̼��غ���. ���� ó���� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : ������ 2014 MB��
*/

int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int altmonth(int y, int m) {
    if (m != 2) return m;
    if ((y & 3) || !(y % 100) && y % 400) return 2;
    else return 0;
}

int main(void) {
    int n, y = 2014, m = 4, d = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        d++;
        if (d > days[altmonth(y, m)]) {
            d = 1;
            m++;
        }
        if (m > 12) {
            y++;
            m = 1;
        }
    }
    printf("%d-%02d-%02d", y, m, d);
    return 0;
}