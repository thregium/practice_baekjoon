#include <stdio.h>

/*
���� : ��� �м��� ������ ������ ������ ���ǵȴ�� �Ѵٸ�, N(N <= 10^7)��° �м��� ã�´�.

�ذ� ��� : �и�� ������ ���� ���� ���� �и�, ���ڷ� ������ ���� ã��,
���⿡ ���� �и�� ���ڸ� ��ġ�ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : SEERC 2004 I��
*/

int main(void) {
    int x, i, a, b, s = 0;
    while (scanf("%d", &x) != EOF) {
        s = 0;
        for (i = 0; i < x; s++) i += s;
        a = i - x + 1;
        b = s - (i - x + 1);
        if (s % 2) printf("TERM %d IS %d/%d\n", x, b, a);
        else printf("TERM %d IS %d/%d\n", x, a, b);
    }
    return 0;
}