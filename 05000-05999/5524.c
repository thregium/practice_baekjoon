#include <stdio.h>
#include <ctype.h>

/*
���� : 20�� ������ ���ڿ�(��ҹ���) N(N <= 100)���� �־��� ��, �� ���ڿ��� �ҹ��ڷ� ��ȯ�� ���� ����Ѵ�.

�ذ� ��� : tolower()�Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : JOI 2013 P3 / 2014 P4��
*/

char s[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; s[j]; j++) printf("%c", tolower(s[j]));
        printf("\n");
    }
    return 0;
}