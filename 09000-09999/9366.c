#include <stdio.h>

/*
���� : �ﰢ���� �� ���� ���̰� �־��� ��, �� �ﰢ���� ������ ���Ѵ�. ��, �ﰢ���� ���� �ʴ� ��쵵 ���� ���Ѵ�.

�ذ� ��� : �� ���� ������ �� ���� �� �̻��̸� �ﰢ���� ���� �ʴ´�. �� ���� ��� ������ ���ﰢ���̰�,
�� ���� ������ �̵, �ƴϸ� �ε�ﰢ���̴�.

�ֿ� �˰��� : ����, ������

��ó : LCPC 2011 I��
*/

int main(void) {
    int t, a, b, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", tt);
        if (a >= b + c || b >= a + c || c >= a + b) printf("invalid!\n");
        else if (a == b && a == c) printf("equilateral\n");
        else if (a == b || a == c || b == c) printf("isosceles\n");
        else printf("scalene\n");
    }
    return 0;
}