#include <stdio.h>

/*
���� : ������ �־��� ������ �޷¿��� ��, ��, ���� �־��� ��, 1000�� 1�� 1�ϱ��� ���� �� ���� ���Ѵ�.

�ذ� ��� : �޷��� ��¥�� ���� �������� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����, �ùķ��̼�

��ó : JDC 2012 A��
*/

int main(void) {
    int t, y, m, d, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &y, &m, &d);
        r = 1;
        while (!(y == 999 && m == 10 && d == 20)) {
            if (y % 3) {
                d++;
                if (d == 21 || (d == 20 && (~m & 1))) {
                    d = 1;
                    m++;
                }
                if (m == 11) {
                    m = 1;
                    y++;
                }
            }
            else {
                d++;
                if (d == 21) {
                    d = 1;
                    m++;
                }
                if (m == 11) {
                    m = 1;
                    y++;
                }
            }
            r++;
        }
        printf("%d\n", r);
    }
    return 0;
}