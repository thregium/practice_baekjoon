#include <stdio.h>
#include <string.h>

/*
���� : ġ��ģ ������ ���ڿ��� �־��� ��, �̸� �������� �ٲ� ����� ����Ѵ�. ���� 2^31���� �۴�.

�ذ� ��� : �� �� �ڸ����� ���ʷ� �ڸ����� ���س�����.

�ֿ� �˰��� : ����, ����, ���ڿ�

��ó : MidC 1997 D��
*/

char s[64];

int main(void) {
    int l;
    long long n, d;
    while (1) {
        scanf("%s", s);
        l = strlen(s);
        if (l == 1 && s[0] == '0') break;

        d = 1;
        n = 0;
        for (int i = l - 1; i >= 0; i--) {
            n += (s[i] - '0') * d;
            d <<= 1;
            d++;
        }
        printf("%lld\n", n);
    }
    return 0;
}