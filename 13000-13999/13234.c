#include <stdio.h>

/*
���� : �� true / false ���̿� AND / OR�� �־��� �� �־��� ������ ����� ����Ѵ�.

�ذ� ��� : ��� ���ڿ��� OR�� AND�� ��츦 ������ �����Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : AIPO 2016P 1��
*/

char s[3][8];

int main(void) {
    scanf("%s %s %s", s[0], s[1], s[2]);
    if (s[1][0] == 'O') {
        printf("%s", (s[0][0] == 't' || s[2][0] == 't') ? "true" : "false");
    }
    else {
        printf("%s", (s[0][0] == 't' && s[2][0] == 't') ? "true" : "false");
    }
    return 0;
}