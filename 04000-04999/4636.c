#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 9)���� �����(8�� ����, �ҹ���)���� ������ü ����� ���並 �����־���.
���� �� ������� ���� �ִ� ������ü ������ ũ�Ⱑ �־�����, �ٸ� ����� ���並 ������ �����
���� ����� �̸��� ���� ����Ѵ�. ������ ���� �� �� ���̰�, ���Ǵ� 250 ������ �ڿ����̴�.

�ذ� ��� : �� ������ ���Ǹ� ����ϸ� ���� ���ǰ� ū ���並 ���� ����� ���� ���� ������ ���並
���� ����� ���並 ���������� �� �� �ִ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : MidC 2003 A��
*/

char bully[16], victim[16], s[16];

int main(void) {
    int n, hi, lo, a, b, c;
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        hi = -1, lo = 256;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %s", &a, &b, &c, s);
            if (a * b * c > hi) {
                hi = a * b * c;
                strcpy(bully, s);
            }
            if (a * b * c < lo) {
                lo = a * b * c;
                strcpy(victim, s);
            }
        }
        if (hi < 0) return 1;
        printf("%s took clay from %s.\n", bully, victim);
    }
    return 0;
}