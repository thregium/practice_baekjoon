#include <stdio.h>
#include <string.h>

/*
���� : ���� 100 ������ ���ڿ��� �־��� ��, �� ���ڿ����� "BUG"�� ���� ���� ���ڿ��� ����Ѵ�.
��ҹ��ڸ� �����ϰ�, "BUG"�� ���� ���� ���� "BUG"�� ���־� �Ѵ�.

�ذ� ��� : "BUG"�� ���� �� ���� strstr�� ���� "BUG"�� ��ġ�� ã�� strcpy�� strcat�� �̿��� �ش� "BUG"��
���ִ� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : CERC 2007 PB��
*/

char s[2][128];

int main(void) {
    int i = 0, p = 0;
    char* c;
    while (fgets(s[0], 120, stdin)) {
        i = 0;
        while (strstr(s[0], "BUG")) {
            c = strstr(s[0], "BUG");
            *c = '\0';
            strcpy(s[1], s[0]);
            strcat(s[1], c + 3);
            strcpy(s[0], s[1]);
        }
        printf("%s", s[i]);
    }
    return 0;
}