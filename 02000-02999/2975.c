#include <stdio.h>

/*
���� : ���� ���ݰ� ����/���� ����, ����/���ݾ��� �־��� ��, ����/������ ����� ���Ѵ�.
��, �ܾ��� -200 �Ʒ��� ������ ���� ����.

�ذ� ��� : ��츦 ������ �ܾ��� ���� ����, -200 �Ʒ��� ���������� �ٽ� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : NZPC 2004 X��
*/

int main(void) {
    int a, b;
    char c;
    while (1) {
        scanf("%d %c %d", &a, &c, &b);
        if (a == 0 && b == 0 && c == 'W') break;
        if (c == 'W') {
            if (a - b < -200) printf("Not allowed\n");
            else printf("%d\n", a - b);
        }
        else printf("%d\n", a + b);
    }
    return 0;
}