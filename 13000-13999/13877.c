#include <stdio.h>
#include <stdlib.h>

/*
���� : �־��� 7�ڸ� ������ 10������ 8����, 10����, 16������ �о��� ���� ���� ���� 10������ ���Ѵ�.
8������ ���� �� ���ٸ� 0�� ����Ѵ�.

�ذ� ��� : �� ������ ���ڿ� ���·� �Է¹��� ������ 8�̳� 9�� �ִ���(8������ ���� �� ������) Ȯ���� ����
strtoll�� ���� ������ ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : GNY 2016 A��
*/

char s[16];

int main(void) {
    int t, k, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %s", &k, s);
        r = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '9' || s[i] == '8') r = 1;
        }
        if (r) printf("%d 0 %lld %lld\n", k, strtoll(s, NULL, 10), strtoll(s, NULL, 16));
        else printf("%d %lld %lld %lld\n", k, strtoll(s, NULL, 8), strtoll(s, NULL, 10), strtoll(s, NULL, 16));
    }
    return 0;
}
