#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 1000�� ������ ���ڿ��� �־��� ��, �� ���ڿ��� problem�̶�� ���ڿ��� ���ԵǾ����� ���Ѵ�.
��ҹ��ڴ� �Ű澲�� �ʴ´�.

�ذ� ��� : tolower�Լ��� ���� ��� ���ڸ� �ҹ��ڷ� �ٲ� ���� strstr�Լ��� ���� problem�� ���ԵǾ����� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : NAQ 2012 A��
*/

char s[1024];

int main(void) {
    while (fgets(s, 1013, stdin)) {
        for (int i = 0; s[i]; i++) s[i] = tolower(s[i]);
        printf("%s\n", strstr(s, "problem") ? "yes" : "no");
    }
    return 0;
}