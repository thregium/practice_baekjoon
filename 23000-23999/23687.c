#include <stdio.h>

/*
���� : N(N <= 100)���� ���� �ְ�, �� ���� section, subsection, subsubsection���� ������.
�� ���� �̸��� ������ �־��� ��, �� �ٿ� ��ȣ�� �ٿ� ����Ѵ�.

�ذ� ��� : �� section, subsection, subsubsection�� ������ �� ����, ���� + 1�� ���� ����ϸ� �ȴ�.
����� �������� �ش� ������ 1�� ���ϰ�, �Ʒ� ������ 0���� �ʱ�ȭ�� �д�.

�ֿ� �˰��� : ����

��ó : COCI 21/22#2 1��
*/

char buff[32], tit[32];

int main(void) {
    int n, a = 0, b = 0, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", buff, tit);
        if (buff[1] == 'e') {
            printf("%d %s\n", ++a, tit);
            b = 0, c = 0;
        }
        else if (buff[4] == 'e') {
            printf("%d.%d %s\n", a, ++b, tit);
            c = 0;
        }
        else printf("%d.%d.%d %s\n", a, b, ++c, tit);
    }
    return 0;
}
