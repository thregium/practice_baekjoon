#include <stdio.h>

/*
���� : 10000 ������ ���� �־����� �� ���� ��ȣ�� �־��� ��, �� ���� ���� ���� ��ȣ�� ���Ѵ�.

�ذ� ��� : 1������ ���ʷ� ���캸�� �� ���� ��ǥ�� ���ϰ�, ��ǥ�� ���� ���� �ٽ� �ѹ��� ���Ǹ� ��ȣ�� ���Ѵ�.

�ֿ� �˰��� : ����, ������

��ó : Daejeon 2012 D��
*/

int main(void) {
    int t, a, b, x, y, xa, ya;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        x = 1, y = 1;
        for (int i = 1; i < a; i++) {
            if (y == 1) {
                y = x + 1;
                x = 1;
            }
            else {
                x++;
                y--;
            }
        }
        xa = x;
        ya = y;
        x = 1, y = 1;
        for (int i = 1; i < b; i++) {
            if (y == 1) {
                y = x + 1;
                x = 1;
            }
            else {
                x++;
                y--;
            }
        }
        xa += x;
        ya += y;
        x = 1, y = 1;
        for (int i = 1;; i++) {
            if (x == xa && y == ya) {
                printf("%d\n", i);
                break;
            }
            if (y == 1) {
                y = x + 1;
                x = 1;
            }
            else {
                x++;
                y--;
            }
        }
    }
    return 0;
}