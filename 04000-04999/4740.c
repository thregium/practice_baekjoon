#include <stdio.h>
#include <string.h>

/*
���� : �־��� ���ڿ��� ������ ���ڿ��� ����Ѵ�.

�ذ� ��� : ���ڿ��� ���� �� ���̸� Ȯ���ϰ� �������� ���ڿ��� ä�������� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : MidAt 2006 P��
*/

char s[128], r[128];

int main(void) {
    int l;
    while (1) {
        fgets(s, 100, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (!strcmp(s, "***")) break;
        l = strlen(s);
        for (int i = 0; i < l; i++) {
            r[l - i - 1] = s[i];
        }
        r[l] = '\0';
        printf("%s\n", r);
    }
    return 0;
}