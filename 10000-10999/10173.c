#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 80�� ������ ���ڿ��� �־��� ��, ��ҹ��ڸ� �������� �ʰ� nemo��� ���ڿ��� ���ԵǾ����� Ȯ���Ѵ�.

�ذ� ��� : tolower�� ���� ��� ���ڸ� �ҹ��ڷ� �ٲ� ���� strstr�� ���� nemo��� ���ڿ��� �ִ��� ã�ƺ��� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : PLU 2014N 4��
*/

char s[128];

int main(void) {
    int a, b;
    while (1) {
        fgets(s, 100, stdin);
        if (!strcmp(s, "EOI") || !strcmp(s, "EOI\n")) break;
        for (int i = 0; s[i]; i++) {
            s[i] = tolower(s[i]);
        }
        if (strstr(s, "nemo")) printf("Found\n");
        else printf("Missing\n");
    }
    return 0;
}