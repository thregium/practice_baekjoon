#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 2016)�� N�� ����� ���� �� M(M <= 2016)�ڸ��� ����Ѵ�.

�ذ� ��� : N�� N�� ���� ���ڿ��� ���� ����(�ִ� 8064����), M��° �ڸ��� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : ����� 2016 C��
*/

char n[8], s[103000];

int main(void) {
    int m;
    scanf("%s %d", n, &m);
    for (int i = 0; i < strtoll(n, NULL, 10); i++) {
        strcat(s, n);
    }
    s[m] = '\0';
    printf("%s", s);
    return 0;
}